#include <chrono>
#include "Header.h"

using namespace std::chrono;

template<typename Func>
void run(Func f) {
    auto start = high_resolution_clock::now();

    long long res = f();

    auto end = high_resolution_clock::now();
    double t = duration_cast<duration<double, milli>>(end - start).count();

    cout << "Result: " << res << "\n";
    cout << "Time: " << t << " ms\n";
}

int main() {

    int choice;

    while (true) {

        cout << "\nEnter 1 (run) or 2 (exit): ";
        cin >> choice;

        if (choice == 2) {
            cout << "Exit...\n";
            break;
        }

        if (choice == 1) {

            long long  a, b, p;

            cout << "Enter p a b:\n";
            cin >> a >> b >> p;

            cout << "\n--- BRUTE FORCE ---\n";
            run([&]() { return brute_force(a, b, p); });

            cout << "\n--- SPH ---\n";
            run([&]() { return sph(a, b, p); });

        }
        else {
            cout << "Invalid input!\n";
        }
    }

    return 0;
}