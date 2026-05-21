#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

namespace {

struct ClassMetric {
    std::string className;
    int methods;
    int attributes;
    int publicMethods;
    int hiddenMethods;
    int publicAttributes;
    int hiddenAttributes;
    int dit;
    int noc;
    int cbo;
    int rfc;
    double lcom;
    int overrides;
    std::string comment;
};

struct SystemMetric {
    std::string name;
    std::string value;
    std::string explanation;
};

const std::vector<ClassMetric> classMetrics = {
    {"MuseumItem", 6, 2, 6, 0, 0, 2, 0, 1, 1, 6, 0.0, 0,
     "абстрактный базовый класс музейного объекта"},
    {"Exhibit", 3, 2, 3, 0, 0, 2, 1, 3, 1, 7, 0.0, 0,
     "общий класс экспоната, наследуется от MuseumItem"},
    {"Painting", 4, 1, 4, 0, 0, 1, 2, 0, 1, 9, 0.0, 2,
     "картина, переопределяет виртуальные методы"},
    {"Sculpture", 4, 1, 4, 0, 0, 1, 2, 0, 1, 9, 0.0, 2,
     "скульптура, переопределяет виртуальные методы"},
    {"Artifact", 4, 1, 4, 0, 0, 1, 2, 0, 1, 9, 0.0, 2,
     "артефакт, переопределяет виртуальные методы"},
    {"Hall", 5, 2, 5, 0, 0, 2, 0, 0, 1, 5, 0.0, 0,
     "зал музея, связан с Museum"},
    {"Museum", 15, 4, 15, 0, 0, 4, 0, 0, 4, 24, 1.0, 0,
     "центральный класс: залы, коллекция, каталог"},
    {"Catalog", 1, 0, 1, 0, 0, 0, 0, 0, 2, 4, 0.0, 0,
     "поиск экспонатов в контейнере"},
    {"Guide", 5, 2, 5, 0, 0, 2, 0, 0, 2, 9, 0.0, 0,
     "гид хранит маршрут из музейных объектов"},
    {"Visitor", 3, 2, 3, 0, 0, 2, 0, 0, 1, 4, 0.0, 0,
     "посетитель связан с гидом"},
    {"MyContainer", 23, 4, 20, 3, 0, 4, 0, 0, 3, 28, 1.0, 0,
     "шаблонный контейнер проекта"},
    {"IPending", 2, 0, 2, 0, 0, 0, 0, 1, 1, 2, 0.0, 0,
     "интерфейс отложенного вызова"},
    {"Pending", 2, 2, 2, 0, 0, 2, 1, 0, 2, 4, 0.0, 1,
     "шаблонная реализация IPending"},
    {"PendingQueue", 5, 1, 5, 0, 0, 1, 0, 0, 2, 8, 0.0, 0,
     "очередь отложенных вызовов семинара 6"},
};

const std::vector<SystemMetric> systemMetrics = {
    {"MIF", "0.20",
     "унаследованные методы есть в ветке MuseumItem -> Exhibit -> потомки и IPending -> Pending"},
    {"AHF", "1.00",
     "все 24 атрибута классов закрыты через private или protected"},
    {"POF", "0.09",
     "7 переопределений виртуальных методов на 82 объявленных метода"},
    {"COF", "0.09",
     "17 реальных связей между 14 классами при 182 возможных направленных связях"},
    {"MHF", "0.04",
     "скрыты только 3 вспомогательных метода MyContainer из 82 методов"},
    {"CHF", "0.00",
     "анализируемые классы объявлены в заголовках и не скрыты внутри модулей"},
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

void printArchitecture() {
    std::cout << "\nОсновные иерархии наследования:\n";
    std::cout << "  MuseumItem -> Exhibit -> Painting, Sculpture, Artifact\n";
    std::cout << "  IPending -> Pending\n";
    std::cout << "\nКлючевые связи:\n";
    std::cout << "  Museum хранит залы, коллекцию экспонатов и Catalog.\n";
    std::cout << "  Guide хранит маршрут из MuseumItem*, Visitor связан с Guide.\n";
    std::cout << "  PendingQueue хранит отложенные действия через IPending.\n";
}

void printClassMetrics() {
    std::cout << "\nБазовые метрики по классам:\n";
    std::cout << std::left
              << std::setw(16) << "Класс"
              << std::setw(5) << "Meth"
              << std::setw(5) << "Attr"
              << std::setw(5) << "PubM"
              << std::setw(5) << "HidM"
              << std::setw(5) << "PubA"
              << std::setw(5) << "HidA"
              << std::setw(5) << "DIT"
              << std::setw(5) << "NOC"
              << std::setw(5) << "CBO"
              << std::setw(5) << "RFC"
              << std::setw(7) << "LCOM"
              << std::setw(5) << "Ovr"
              << "Комментарий\n";
    std::cout << std::string(112, '-') << '\n';

    for (const ClassMetric& metric : classMetrics) {
        std::cout << std::left
                  << std::setw(16) << metric.className
                  << std::setw(5) << metric.methods
                  << std::setw(5) << metric.attributes
                  << std::setw(5) << metric.publicMethods
                  << std::setw(5) << metric.hiddenMethods
                  << std::setw(5) << metric.publicAttributes
                  << std::setw(5) << metric.hiddenAttributes
                  << std::setw(5) << metric.dit
                  << std::setw(5) << metric.noc
                  << std::setw(5) << metric.cbo
                  << std::setw(5) << metric.rfc
                  << std::setw(7) << std::fixed << std::setprecision(1) << metric.lcom
                  << std::setw(5) << metric.overrides
                  << metric.comment << '\n';
    }
}

void printSystemMetrics() {
    std::cout << "\nСистемные метрики MOOD:\n";
    std::cout << "Метрика    Значение    Пояснение\n";
    std::cout << std::string(86, '-') << '\n';

    for (const SystemMetric& metric : systemMetrics) {
        std::cout << std::left
                  << std::setw(10) << metric.name
                  << std::setw(12) << metric.value
                  << metric.explanation << '\n';
    }
}

void printInterpretation() {
    std::cout << "\nИнтерпретация:\n";
    std::cout << "  - DIT не превышает 2: иерархия MuseumItem понятная и неглубокая.\n";
    std::cout << "  - Самые связанные классы: Museum, MyContainer, Guide и PendingQueue.\n";
    std::cout << "  - POF невысокий, но полиморфизм используется там, где он нужен: "
              << "в экспонатах и очереди отложенных вызовов.\n";
    std::cout << "  - AHF равен 1.00: поля классов не открыты напрямую.\n";
}

void printRecommendations() {
    std::cout << "\nРекомендации по рефакторингу:\n";
    std::cout << "  1. При росте проекта вынести построение маршрутов из Museum в отдельный сервис.\n";
    std::cout << "  2. Связать Hall и Exhibit более явно, если нужно хранить экспонаты внутри залов.\n";
    std::cout << "  3. Добавить автоматическую утилиту расчета метрик по заголовочным файлам.\n";
    std::cout << "  4. Разделить демонстрационный код и предметную логику при расширении main.cpp.\n";
}

}  // namespace

int main() {
    printLine();
    std::cout << "СЕМИНАР 7-8. РАСЧЕТ МЕТРИК ООП\n";
    printLine();

    std::cout << "\nПредметная область: музей, вариант 23\n";
    std::cout << "Расчет выполнен вручную по исходному коду проекта.\n";

    printArchitecture();
    printClassList();
    printClassMetrics();
    printSystemMetrics();
    printInterpretation();
    printRecommendations();

    std::cout << "\nВывод: проект подходит для анализа метрик ООП, так как содержит "
              << "наследование, полиморфизм, инкапсуляцию, композицию и агрегацию.\n";

    return 0;
}
