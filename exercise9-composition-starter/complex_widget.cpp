////////////////////////////////////////////////////////
// ECE 3574 - Exercise 9: Qt widgets
//
#include "complex_widget.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>

ComplexWidget::ComplexWidget(QWidget *parent) : QWidget(parent), real(0), imaginary(0), magnitude(0), phase(0){
    realedit = new QLineEdit(this);
    imaginedit  = new QLineEdit(this);
    magnitudelab = new QLabel("Magnitude: 0", this);
    phaselab = new QLabel("Phase: 0", this);
    update = new QPushButton("Update", this);

    QVBoxLayout *mainlay = new QVBoxLayout;
    QHBoxLayout *inputlay = new QHBoxLayout;
    inputlay->addWidget(new QLabel("Real: "));
    inputlay->addWidget(realedit);
    inputlay->addWidget(new QLabel("Imaginary: "));
    inputlay->addWidget(imaginedit);

    mainlay->addWidget(inputlay);
    mainlay->addWidget(update);
    mainlay->addWidget(magnitudelab);
    mainlay->addWidget(phaselab);

    setLayout(mainlay);

    connect(update, &QPushButton::clicked, this, &ComplexWidget::updatevalues)
}

void ComplexWidget::updatevalues(){
    real = realedit->text().toDouble();
    imaginary = imaginedit->text().toDouble();
    magnitude = std::sqrt(real * real + imaginary * imaginary);
    phase = std::atan2(imaginary,real);
    magnitudelab->setText(QString("magnitude: %1").arg(magnitude));
    phaselab->setText(QString("phase: %1").arg(phase));
}

double ComplexWidget::getRealPart() const{
    return real;
}
double ComplexWidget::getImaginaryPart() const{
    return imaginary; 
}
double ComplexWidget::getMagnitude() const{
    return magnitude; 
}
double ComplexWidget::getPhase() const{
    return phase; 
}
