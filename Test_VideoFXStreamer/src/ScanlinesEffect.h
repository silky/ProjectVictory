#pragma once

#include "ofMain.h"
#include "BaseEffect.h"

class ScanlinesEffect : public BaseEffect {
public:
    
    float nIntensity;
    float sIntensity;
    float sCount;
    
    ScanlinesEffect() {
        passes = 1;
        internalFormat = GL_RGBA;
        pathToShader = "shaders/scanlines.frag";
        parseShader();
        name = "scanlines";
    }
    
    void setupGUI( ofxUISuperCanvas *gui ) {
        gui->addSpacer();
        gui->addToggle( "SCANLINES EFFECT", &enabled );
//        addWidget( gui->addSlider( "COUNT", 50, 1000, &sCount ) );
//        addWidget( gui->addSlider( "sINTENSITY", 0, 2, &sIntensity ) );
        //        addWidget( gui->addSlider( "nINTENSITY", 0, 2, &nIntensity ) );
        settings = new ofxUISuperCanvas( "SCANLINES EFFECT", ofRandom(ofGetWidth()), 0, 200, 200 );
        settings->setColorBack( ofColor( ofColor::yellow, 150 ) );
        settings->addSlider( "AMOUNT", 0.0, 1.0, &amount );
        settings->addSlider( "COUNT", 50, 1000, &sCount );
        settings->addSlider( "sINTENSITY", 0, 2, &sIntensity );
        settings->addSlider( "nINTENSITY", 0, 2, &nIntensity );
        settings->autoSizeToFitWidgets();
        settings->loadSettings( "GUI/effects/" + name + ".xml" );

    }
    
    void setCustomUniforms() {
        shader.setUniform1f( "nIntensity", nIntensity );
        shader.setUniform1f( "sIntensity", sIntensity );
        shader.setUniform1f( "sCount", sCount );
    }
    
};