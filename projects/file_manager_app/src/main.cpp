#include <QApplication>
#include "main_window.hpp"
#include <QLoggingCategory>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QLoggingCategory::setFilterRules("qt.qpa.wayland.textinput=false");
    
    MainWindow window;
    window.show();
    
    return app.exec();
}
