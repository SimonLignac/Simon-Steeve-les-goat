#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget fenetre;
    fenetre.setWindowTitle("Application Simon");
    fenetre.resize(300, 200);

    QPushButton bouton("Clique ici si t'es un goat", &fenetre);
    bouton.setGeometry(90, 80, 150, 40);

    fenetre.show();

    return app.exec();
}
