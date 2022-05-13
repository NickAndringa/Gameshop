#include <ctime>
#include <iostream>
#include "include/Game.hpp"
#include "include/Person.hpp"

int main()
{
    std::time_t result = std::time(NULL);
    std::cout << std::asctime(std::localtime(&result));
    time_t curr_time = time(NULL);
    tm *tm_local = localtime(&curr_time);
    int releaseDate1 = tm_local->tm_year + 1899; // 1 jaar geleden
    int releaseDate2 = tm_local->tm_year + 1898; // 2 jaar geleden
    
    Game g1("Just Cause 3", releaseDate1 , 49.98);
    Game g2("Need for Speed: Rivals", releaseDate2 , 45.99);
    Game g3("Need for Speed: Rivals", releaseDate2 , 45.99);
    
    Person p1(200, "Eric");
    Person p2(55, "Hans");
    Person p3(185, "Arno");
    
    // Druk de volgende transacties af (pas de code aan)
    p1.buy(g1);
    p1.buy(g2);
    p1.buy(g3);
    p2.buy(g2);
    p2.buy(g1);
    p3.buy(g3);
    
    // Druk personen p1, p2 en p3 nu af naar de console
    std::cout << p1 << '\n' << p2 << '\n' << p3 << '\n';
    // Druk de volgende transacties af (pas de code aan)
    p1.sell(g1, p3);
    p2.sell(g2, p3);
    p2.sell(g1, p1);
    
    // Druk personen p1, p2 en p3 nu af naar de console
    std::cout << p1 << '\n' << p2 << '\n' << p3 << '\n';
    return 0;
}