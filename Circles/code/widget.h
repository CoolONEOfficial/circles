#ifndef WIDGET_H
#define WIDGET_H

//

#include <QWidget>

#define ver v0.5

//

namespace Ui {
class Widget;
}

struct Point
{
    int x,y;
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    //

        static const int Num = 50;

        QColor OnColor;

        QImage settingsIcon;

        QFont font;

    //

        Point masP[Num];

    //

        QFont lFont;

    //

        QColor bColor, // Background Color
               fColor; // Fill Color

    //

        int x,y,
            size,
            mas[2][Num],
            R,G,B,
            speedR,
            numCircles,
            timerID;

    //

        bool rDown,gDown,bDown, settings;

    //

        void paintEvent(QPaintEvent * );
        void changeColor();
        void keyPressEvent(QKeyEvent *event);
        void resizeEvent(QResizeEvent *);

        void drawNiceLines(QPainter &p);
        void drawLines(QPainter &p);
        void drawCircles(QPainter &p);
        void drawBackground(QPainter &p);
        void drawLabels(QPainter &p);
        void setFill(QPainter &p);
        void drawLabel(QPainter &p, QRect rect, QString label, bool val, Qt::Alignment align);
        void openSettings();
        void loadAll();
        void setFontAll();

    //

private slots:
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void timerEvent(QTimerEvent *);
    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
