#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

namespace {

struct ClassMetric {
    std::string className;
    int wmc;
    int dit;
    int noc;
    int cbo;
    int rfc;
    int lcom;
    std::string comment;
};

struct SystemMetric {
    std::string name;
    std::string value;
    std::string explanation;
};

const std::vector<ClassMetric> classMetrics = {
    {"Account", 9, 0, 3, 2, 14, 1, "базовый класс счета"},
    {"SavingsAccount", 5, 1, 0, 1, 11, 0, "сберегательный счет"},
    {"CreditAccount", 6, 1, 0, 2, 12, 1, "кредитный счет"},
    {"DepositAccount", 5, 1, 0, 1, 10, 1, "депозитный счет"},
    {"Bank", 10, 0, 0, 6, 22, 3, "центральный класс системы"},
    {"Client", 7, 0, 0, 4, 15, 2, "клиент банка"},
    {"Department", 5, 0, 0, 3, 10, 1, "отделение банка"},
    {"Transaction", 6, 0, 0, 3, 12, 1, "банковская операция"},
    {"CommissionCalculator", 4, 0, 0, 2, 7, 0, "расчет комиссии"},
    {"PendingQueue", 5, 0, 0, 2, 8, 0, "очередь отложенных вызовов"},
    {"IPending", 2, 0, 1, 0, 2, 0, "интерфейс отложенного вызова"},
    {"Pending", 2, 1, 0, 3, 4, 0, "шаблонная реализация вызова"},
};

const std::vector<SystemMetric> systemMetrics = {
    {"MIF", "0.16", "доля унаследованных методов умеренно низкая"},
    {"AHF", "0.18", "доля унаследованных атрибутов небольшая"},
    {"POF", "0.54", "потомки Account активно переопределяют поведение"},
    {"COF", "0.23", "связность классов умеренная"},
    {"MHF", "0.05", "скрытых методов мало, основная часть методов публичная"},
    {"CHF", "1.00", "атрибуты скрыты через private или protected"},
};

void printLine() {
    std::cout << "========================================================================\n";
}

void printClassList() {
    std::cout << "\nАнализируемые классы:\n";
    for (const ClassMetric& metric : classMetrics) {
        std::cout << "  - " << metric.className << '\n';
    }
}

void printClassMetrics() {
    std::cout << "\nМетрики по классам:\n";
    std::cout << std::left
              << std::setw(24) << "Класс"
              << std::setw(6) << "WMC"
              << std::setw(6) << "DIT"
              << std::setw(6) << "NOC"
              << std::setw(6) << "CBO"
              << std::setw(6) << "RFC"
              << std::setw(7) << "LCOM"
              << "Комментарий\n";
    std::cout << std::string(88, '-') << '\n';

    for (const ClassMetric& metric : classMetrics) {
        std::cout << std::left
                  << std::setw(24) << metric.className
                  << std::setw(6) << metric.wmc
                  << std::setw(6) << metric.dit
                  << std::setw(6) << metric.noc
                  << std::setw(6) << metric.cbo
                  << std::setw(6) << metric.rfc
                  << std::setw(7) << metric.lcom
                  << metric.comment << '\n';
    }
}

void printSystemMetrics() {
    std::cout << "\nСистемные метрики:\n";
    std::cout << std::left
              << std::setw(18) << "Метрика"
              << std::setw(20) << "Значение"
              << "Пояснение\n";
    std::cout << std::string(74, '-') << '\n';

    for (const SystemMetric& metric : systemMetrics) {
        std::cout << std::left
                  << std::setw(18) << metric.name
                  << std::setw(20) << metric.value
                  << metric.explanation << '\n';
    }
}

}  // namespace

int main() {
    printLine();
    std::cout << "СЕМИНАР 7–8. РАСЧЕТ МЕТРИК ООП\n";
    printLine();

    std::cout << "\nАнализируемая предметная область: банковская система\n";
    std::cout << "Основная иерархия наследования:\n";
    std::cout << "Account -> SavingsAccount, CreditAccount, DepositAccount\n";
    std::cout << "Дополнительная иерархия: IPending -> Pending\n";

    printClassList();
    printClassMetrics();
    printSystemMetrics();

    std::cout << "\nКраткий вывод:\n";
    std::cout << "Глубина наследования небольшая, связи между классами умеренные.\n";
    std::cout << "Bank и Client имеют наибольшую связность, так как являются "
              << "центральными классами предметной области.\n";
    std::cout << "Инкапсуляция соблюдается, а полиморфизм используется в счетах "
              << "и очереди отложенных вызовов.\n";

    return 0;
}
