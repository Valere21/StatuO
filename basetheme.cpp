#include "basetheme.h"

BaseTheme::BaseTheme(){

}

BaseTheme::BaseTheme(QObject *parent) : QObject(parent) {

}

QObject* BaseTheme::baseThemeSingletonProvider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    BaseTheme* theme = new BaseTheme();
    return theme;
}

int BaseTheme::getIndicator_height_mm() const
{
    return indicator_height_mm;
}

int BaseTheme::getIndicator_width_mm() const
{
    return indicator_width_mm;
}

int BaseTheme::getRectIndicatorTitle_width_mm() const
{
    return rectIndicatorTitle_width_mm;
}

int BaseTheme::getScenario_width_mm() const
{
    return scenario_width_mm;
}

int BaseTheme::getList_topMargin_menu_mm() const
{
    return list_topMargin_menu_mm;
}

int BaseTheme::getScenario_leftMargin_title_mm() const
{
    return scenario_leftMargin_title_mm;
}

int BaseTheme::getPopUp_width_mm() const
{
    return popUp_width_mm;
}

int BaseTheme::getPopUp_height_mm() const
{
    return popUp_height_mm;
}

int BaseTheme::getList_width_mm() const
{
    return list_width_mm;
}

int BaseTheme::getList_height_mm() const
{
    return list_height_mm;
}

int BaseTheme::getPopUp_image_width_mm() const
{
    return popUp_image_width_mm;
}

int BaseTheme::getPopUp_image_height_mm() const
{
    return popUp_image_height_mm;
}

int BaseTheme::getIndicatorName_width_mm() const
{
    return indicatorName_width_mm;
}


