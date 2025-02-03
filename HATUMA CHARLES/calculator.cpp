//RUN THE CODES USING KALI COMPILER TO INSTALL REQUIRED PACKAGES
//USE THE FOLLOWING COMMAND g++ calculator.cpp -o calculatr `fltk-config --cxxflags --ldflags`
//./calculator

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
#include <string>
#include <sstream>
#include <iomanip>  // For std::setprecision

// USING FLTK Library
using namespace std;

Fl_Output *display;
string current_input;
string last_input;
char operation = 0;
bool has_decimal = false;
bool scientific_mode = false;  // Flag to toggle scientific mode

void button_cb(Fl_Widget *w, void *v) {
    const char *label = ((Fl_Button*)w)->label();

    if ((label[0] >= '0' && label[0] <= '9') || label[0] == '.') {
        // Allow only one decimal point in the current input
        if (label[0] == '.' && has_decimal) return;
        
        if (label[0] == '.') has_decimal = true;
        
        current_input += label;
        display->value(current_input.c_str());
    } else if (label[0] == 'C') {
        // Clear all inputs and reset state
        current_input = "";
        last_input = "";
        operation = 0;
        has_decimal = false;
        display->value("");
    } else if (label[0] == '=') {
        if (!last_input.empty() && !current_input.empty() && operation) {
            double result = 0.0;
            bool error = false;

            // Check if the operation is modulus and handle it as integer division
            if (operation == '%') {
                try {
                    int num1 = std::stoi(last_input);
                    int num2 = std::stoi(current_input);
                    if (num2 == 0) {
                        display->value("Error: Div by 0");
                        error = true;
                    } else {
                        result = num1 % num2;
                    }
                } catch (...) {
                    display->value("Error: Invalid Input");
                    error = true;
                }
            } else {
                double num1 = std::stod(last_input);
                double num2 = std::stod(current_input);

                switch (operation) {
                    case '+': result = num1 + num2; break;
                    case '-': result = num1 - num2; break;
                    case '*': result = num1 * num2; break;
                    case '/':
                        if (num2 == 0) {
                            display->value("Error: Div by 0");
                            error = true;
                        } else {
                            result = num1 / num2;
                        }
                        break;
                }
            }

            if (!error) {
                std::stringstream ss;
                if (scientific_mode) {
                    ss << std::scientific << std::setprecision(4) << result;
                } else {
                    ss << std::fixed << std::setprecision(2) << result;
                }
                display->value(ss.str().c_str());

                current_input = ss.str();  // Store result for further operations
            }
            last_input = "";
            operation = 0;
            has_decimal = current_input.find('.') != std::string::npos;
        }
    } else if (string(label) == "Sci") {
        // Toggle scientific mode on or off
        scientific_mode = !scientific_mode;
        display->value(scientific_mode ? "Sci Mode On" : "Sci Mode Off");
    } else {
        // Handling operator input
        if (!current_input.empty()) {
            last_input = current_input;
            current_input = "";
            operation = label[0];
            has_decimal = false;
            display->value("");
        }
    }
}

int main() {
    Fl_Window *window = new Fl_Window(300, 300, "Calculator");
    display = new Fl_Output(10, 10, 260, 40, "");
    display->box(FL_BORDER_BOX);
    int button_width = 50, button_height = 40;
    int start_x = 10, start_y = 60;
    
    // Create numeric buttons (0-9 and '.')
    for (int i = 0; i < 10; i++) {
        int row = (i == 0) ? 3 : (i - 1) / 3;
        int col = (i == 0) ? 1 : (i - 1) % 3;
        string label = to_string(i);
        Fl_Button *button = new Fl_Button(start_x + col * button_width, start_y + row * button_height, button_width, button_height, label.c_str());
        button->copy_label(label.c_str());
        button->callback(button_cb);
    }

    // Decimal point button
    Fl_Button *dot_button = new Fl_Button(start_x + 2 * button_width, start_y + 3 * button_height, button_width, button_height, ".");
    dot_button->callback(button_cb);

    // Create operation buttons
    const char* operations[] = { "+", "-", "*", "/", "%", "C", "=", "Sci" };
    for (int i = 0; i < 8; i++) {
        int row = i / 2;
        int col = i % 2;
        Fl_Button *op_button = new Fl_Button(start_x + 3 * button_width + col * button_width, start_y + row * button_height, button_width, button_height, operations[i]);
        op_button->callback(button_cb);
    }

    window->end();
    window->show();
    return Fl::run();
}


