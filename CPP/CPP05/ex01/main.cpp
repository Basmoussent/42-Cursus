#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat high("High", 1);
        Bureaucrat low("Low", 150);
        Form form1("Tax Form", 100, 50);
        Form form2("Top Secret", 1, 1);

        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

        low.signForm(form1);  // Should fail
        high.signForm(form1); // Should succeed
        high.signForm(form2); // Should succeed

        // Test copy
        Form form3(form1);
        std::cout << form3 << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
