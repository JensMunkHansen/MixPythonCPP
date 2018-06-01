#include <QApplication>
#include <QMainWindow>

#include <iostream>
#include "Python.h"

class PythonQt
{

public:

  PythonQt()
  {
    char name[] = "test";
    Py_SetProgramName(name);
    Py_Initialize();

    std::string code =
        "from PySide import QtGui\n"
        ""
        "all_widgets = QtGui.QApplication.instance().allWidgets()\n"
        "window = None\n"
        "for widget in all_widgets:\n"
        "    if str(widget.objectName()) == \"main_window\":\n"
        "      window = widget\n"
        "      break\n"
        ""
        "def message_box():\n"
        "    QtGui.QMessageBox.information(None, 'Test', 'Hello!', \
                      QtGui.QMessageBox.Ok)\n"
        "    QtGui.QApplication.instance().quit()\n"
        ""
        "button = QtGui.QPushButton('Press Me')\n"
        "button.clicked.connect(message_box)\n"
        "window.setCentralWidget(button)\n"
        "window.move(600, 300)\n"
        "window.show()";

    PyRun_SimpleString(code.c_str());
  }

};

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  QMainWindow win;
  win.setObjectName("main_window");

  PythonQt python_code;

  a.exec();
}
