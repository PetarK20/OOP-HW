#include "Library.h"
using namespace std;

int main() {

    Library lib;
    
    Author a{"Ivan Vazov", 1850};
    Book b1{"Pod igoto", a, 1894, 25.50, "ISBN-001"};
    Book b2{"Nema zemya", a, 1900, 18.90, "ISBN-002"};

    
    lib.addBook(b1);
    lib.addBook(b2);
    
    lib.addMember(Member{"Petar Kolev", "M001", 2025});
    
    lib.addMember(Member{"Ivan Vazov", "M001", 2025}); 

    lib.addMember(Member{"Yordan Vladov", "M002", 2025});

    cout << "\n" << lib.to_string() << "\n";

    cout << "## 1. Loan Test ##\n";
    

    if (lib.loanBook("ISBN-001", "M001", "2025-12-03", "2025-12-07")) {
        cout << "Loan created.\n";
    } else {
        cout << "Loan failed.\n";
    }

    if (lib.loanBook("ISBN-001", "M001", "2025-12-04", "2025-12-20")) {
        cout << "Loan created.\n";
    } else {
        cout << "Loan failed.\n";
    }

    cout << "\n## 2. Availability Check ##\n";
    cout << "Available ISBN-001? " << boolalpha << lib.isBookAvailable("ISBN-001") << "\n"; 
    cout << "Available ISBN-003? " << boolalpha << lib.isBookAvailable("ISBN-003") << "\n"; 
    cout << "Available ISBN-002? " << boolalpha << lib.isBookAvailable("ISBN-002") << "\n"; 
    cout << "\nCurrent Library State:\n";
    cout << lib.to_string() << "\n";

    cout << "\n## 3. Return Book ##\n";
    lib.returnBook("ISBN-001", "M001");
    cout << "Available ISBN-001? " << boolalpha << lib.isBookAvailable("ISBN-001") << "\n"; 
    
    
    cout << "\n## 4. Find By Author ##\n";
    
    for (const auto& bk : lib.findBooksByAuthor("Ivan Vazov")) {
        cout << "Found: " << bk.getTitle() << "\n";
    }

    cout << "\n## 5. Books By Year (1900) ##\n";
    for (const auto& bk : lib.getBooksByYear(1900)) {
        cout << "Found: " << bk.getTitle() << "\n";
    }

    cout << "\n## 6. Final Library State ##\n";
    cout << lib.to_string() << "\n";
    
    
    return 0;
}