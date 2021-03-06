/*
 * Slices.h - Class for adding x, y and z and editing slice colormap.
 *
 * Author: Patrick O'Leary
 * Created: August 11, 2008
 * Copyright: 2008. All rights reserved.
 */
#ifndef SLICES_INCLUDED
#define SLICES_INCLUDED

/* Vrui includes */
#include <GL/GLColorMap.h>
#include <GLMotif/Blind.h>
#include <GLMotif/Popup.h>
#include <GLMotif/PopupWindow.h>
#include <GLMotif/RadioBox.h>
#include <GLMotif/RowColumn.h>
#include <GLMotif/Slider.h>
#include <GLMotif/StyleSheet.h>
#include <GLMotif/TextField.h>
#include <Misc/CallbackData.h>
#include <Misc/CallbackList.h>

// begin Forward Declarations
class ColorMap;
class Scene;
class Storage;
class SwatchesWidget;
class Toirt_Samhlaigh;
class Volume;
// end Forward Declarations

class Slices: public GLMotif::PopupWindow {
public:
    Slices(Scene * _scene, unsigned char * _sliceColormap, Toirt_Samhlaigh & _toirt_samhlaigh, Volume * _volume);
    virtual ~Slices(void);
    void changeSlicesColorMap(int colormap) const;
    void changeSlicesColorMapCallback(GLMotif::RadioBox::ValueChangedCallbackData * callBackData);
    void exportSlicesColorMap(unsigned char* colormap) const;
    Storage * getColorMap(void) const;
    void setColorMap(Storage* storage);
    const ColorMap* getSlicesColorMap(void) const;
    ColorMap* getSlicesColorMap(void);
    void setSlicesColorMap(int colorMapCreationType, double _minimum, double _maximum);
    Misc::CallbackList& getSlicesColorMapChangedCallbacks(void);
    void loadColorMap(const char* fileName);
    void saveColorMap(const char* fileName) const;
    void sliceColorMapChangedCallback(Misc::CallbackData * callBackData);
    void sliderCallback(GLMotif::Slider::ValueChangedCallbackData * callBackData);
    void toggleSelectCallback(GLMotif::ToggleButton::ValueChangedCallbackData * callBackData);
private:
    ColorMap * colorMap;
    GLMotif::Blind * colorPane;
    GLMotif::Slider * colorSliders[3];
    Scene * scene;
    unsigned char * sliceColormap;
    SwatchesWidget * swatchesWidget;
    Toirt_Samhlaigh & toirt_samhlaigh;
    Volume * volume;
    GLMotif::TextField* xSliceValue;
    GLMotif::TextField* ySliceValue;
    GLMotif::TextField* zSliceValue;
    void colorMapChangedCallback(Misc::CallbackData * callbackData);
    void colorSliderCallback(Misc::CallbackData * callbackData);
    void colorSwatchesWidgetCallback(Misc::CallbackData * callbackData);
    void controlPointChangedCallback(Misc::CallbackData * callbackData);
    GLMotif::RowColumn * createButtonBox(GLMotif::RowColumn * & colorMapDialog);
    GLMotif::RowColumn * createColorEditor(const GLMotif::StyleSheet & styleSheet, GLMotif::RowColumn * & colorMapDialog);
    void createColorMap(const GLMotif::StyleSheet & styleSheet, GLMotif::RowColumn * & colorMapDialog);
    void createColorMapDialog(const GLMotif::StyleSheet & styleSheet);
    void createColorPanel(const GLMotif::StyleSheet & styleSheet, GLMotif::RowColumn * & colorMapDialog);
    GLMotif::Slider * createColorSlider(const char * title, GLMotif::Color color, const GLMotif::StyleSheet & styleSheet,
            GLMotif::RowColumn * colorSlidersBox);
    GLMotif::RowColumn * createColorSliderBox(const GLMotif::StyleSheet & styleSheet, GLMotif::RowColumn * colorEditor);
    void createColorSliders(const GLMotif::StyleSheet & styleSheet, GLMotif::RowColumn * colorEditor);
    void createColorSwatchesWidget(const GLMotif::StyleSheet & styleSheet, GLMotif::RowColumn * & colorEditor);
    GLMotif::Popup * createSliceColorMapSubMenu(void);
    void createXSlices(GLMotif::RowColumn * & xyzSlicesRowColumn, const GLMotif::StyleSheet & styleSheet);
    void createXYZSlices(const GLMotif::StyleSheet & styleSheet, GLMotif::RowColumn * & colorMapDialog);
    void createYSlices(GLMotif::RowColumn * & xyzSlicesRowColumn, const GLMotif::StyleSheet & styleSheet);
    void createZSlices(GLMotif::RowColumn * & xyzSlicesRowColumn, const GLMotif::StyleSheet & styleSheet);
    void initialize(void);
    void removeControlPointCallback(Misc::CallbackData * callbackData);
};

#endif
