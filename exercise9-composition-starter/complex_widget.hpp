////////////////////////////////////////////////////////
// ECE 3574 - Exercise 9: Qt widgets
//
#ifndef COMPLEX_WIDGET_H
#define COMPLEX_WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class ComplexWidget : public QWidget
{
    Q_OBJECT

    public: 
        explicit ComplexWidget(QWidget *part = nullptr);
        double getRealPart() const;
        double getImaginaryPart() const;
        double getMagnitude() const;
        double getPhase() const;

    private slots:
        void updatevalues();

    private: 
        QLineEdit *realedit;
        QLineEdit *imaginedit;

        QLabel *magnitudelab;
        QLabel *phaselab;

        QPushButton *update;

        double real;
        double imaginary; 
        double magnitude;
        double phase;
    
};

#endif
