#ifndef BASETHEME_H
#define BASETHEME_H

#include <QObject>
#include <QJSEngine>
#include <QQmlEngine>

class BaseTheme : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int indicator_width_mm READ getIndicator_width_mm CONSTANT FINAL)
    Q_PROPERTY(int indicator_height_mm READ getIndicator_height_mm CONSTANT FINAL)
    Q_PROPERTY(int indicatorName_width_mm READ getIndicatorName_width_mm CONSTANT FINAL)

    Q_PROPERTY(int rectIndicatorTitle_width_mm READ getRectIndicatorTitle_width_mm CONSTANT FINAL)

    Q_PROPERTY(int list_topMargin_menu_mm READ getList_topMargin_menu_mm CONSTANT FINAL)

    Q_PROPERTY(int scenario_width_mm READ getScenario_width_mm CONSTANT FINAL)
    Q_PROPERTY(int scenario_leftMargin_title_mm READ getScenario_leftMargin_title_mm CONSTANT FINAL)

public:
    BaseTheme();
    BaseTheme(QObject *parent);
    static QObject* baseThemeSingletonProvider(QQmlEngine *engine, QJSEngine *scriptEngine);


    int getIndicator_width_mm() const;
    int getIndicator_height_mm() const;

    int getIndicatorName_width_mm() const;
    int getRectIndicatorTitle_width_mm() const;

    int getList_marge_menu_mm() const;

    int getScenario_width_mm() const;

    int getList_topMargin_menu_mm() const;

    int getScenario_leftMargin_title_mm() const;

    int getPopUp_width_mm() const;

    int getPopUp_height_mm() const;

    int getList_width_mm() const;

    int getList_height_mm() const;

    int getPopUp_image_width_mm() const;

    int getPopUp_image_height_mm() const;

private:

    int indicator_width_mm = 40;
    int indicator_height_mm = 15;

    int indicatorName_width_mm = 90;
    int rectIndicatorTitle_width_mm = 90;

    int list_topMargin_menu_mm = 15;
    int list_width_mm = 150;
    int list_height_mm = 100;


    int scenario_width_mm = 60;
    int scenario_leftMargin_title_mm = 15;

    int popUp_width_mm = 125;
    int popUp_height_mm = 70;
    int popUp_image_width_mm = 40;
    int popUp_image_height_mm = 40;

    Q_PROPERTY(int popUp_width_mm READ getPopUp_width_mm CONSTANT FINAL)
    Q_PROPERTY(int popUp_height_mm READ getPopUp_height_mm CONSTANT FINAL)
    Q_PROPERTY(int list_width_mm READ getList_width_mm CONSTANT FINAL)
    Q_PROPERTY(int list_height_mm READ getList_height_mm CONSTANT FINAL)
    Q_PROPERTY(int popUp_image_width_mm READ getPopUp_image_width_mm CONSTANT FINAL)
    Q_PROPERTY(int popUp_image_height_mm READ getPopUp_image_height_mm CONSTANT FINAL)
};

#endif // BASETHEME_H





















