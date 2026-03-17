#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QRandomGenerator>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget fenetre;
    fenetre.setWindowTitle("Application Simon");
    fenetre.resize(500, 350);

    QPushButton bouton("Clique ici si t'es un goat", &fenetre);
    bouton.setGeometry(140, 140, 220, 60);

    int compteur = 0;

    QObject::connect(&bouton, &QPushButton::clicked, [&]() {
        compteur++;

        int largeur = QRandomGenerator::global()->bounded(400, 801);
        int hauteur = QRandomGenerator::global()->bounded(300, 601);
        int x = QRandomGenerator::global()->bounded(50, 700);
        int y = QRandomGenerator::global()->bounded(50, 400);

        fenetre.resize(largeur, hauteur);
        fenetre.move(x, y);

        int rouge = QRandomGenerator::global()->bounded(256);
        int vert = QRandomGenerator::global()->bounded(256);
        int bleu = QRandomGenerator::global()->bounded(256);

        fenetre.setStyleSheet(
            QString("background-color: rgb(%1, %2, %3);")
                .arg(rouge)
                .arg(vert)
                .arg(bleu)
            );

        int rougeBouton = QRandomGenerator::global()->bounded(256);
        int vertBouton = QRandomGenerator::global()->bounded(256);
        int bleuBouton = QRandomGenerator::global()->bounded(256);

        bouton.setStyleSheet(
            QString("background-color: rgb(%1, %2, %3);"
                    "color: white;"
                    "font-size: 16px;"
                    "border-radius: 10px;")
                .arg(rougeBouton)
                .arg(vertBouton)
                .arg(bleuBouton)
            );

        int maxX = fenetre.width() - bouton.width();
        int maxY = fenetre.height() - bouton.height();

        if (maxX < 0) maxX = 0;
        if (maxY < 0) maxY = 0;

        int newX = QRandomGenerator::global()->bounded(maxX + 1);
        int newY = QRandomGenerator::global()->bounded(maxY + 1);

        bouton.move(newX, newY);

        if (compteur == 1) {
            bouton.setText("Il n'y a qu'un seul goat");
        }
        else if (compteur == 2) {
            bouton.setText("Le seul et l'unique");
        }
        else if (compteur == 3) {
            bouton.setText("Le meilleur du monde");
        }
        else if (compteur == 4) {
            bouton.setText("Le roi absolu");
        }
        else if (compteur == 5) {
            bouton.setText("Le boss final");
        }
        else if (compteur == 6) {
            bouton.setText("Le goat des goats");
        }
        else if (compteur == 7) {
            bouton.setText("Le legendaire Simon");
        }
        else if (compteur == 8) {
            bouton.setText("Personne ne le depasse");
        }
        else if (compteur == 9) {
            bouton.setText("Toujours au sommet");
        }
        else {
            bouton.setText("SIMON LE GOAT");
            fenetre.setWindowTitle("SIMON LE GOAT");
        }
    });

    fenetre.show();

    return app.exec();
}
