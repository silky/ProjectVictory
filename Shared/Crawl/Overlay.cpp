#include "Overlay.h"

void Overlay::init() {
    // add some fake tweets to the crawl
    crawl.init();
//    crawl.addCrawlItem( "aarontweets", "here is my message #shoutout" );
//    crawl.addCrawlItem( "somedude", "#shoutout omg im on tv" );
//    crawl.addCrawlItem( "nikefan", "i like shoes" );
//    crawl.addCrawlItem( "test_user", "im testing stuff" );
//    crawl.addCrawlItem( "hacker", "im hacking stuff" );
//    crawl.addCrawlItem( "social_media_pro", "im tweeting stuff" );
    
    textOverlay.init();
    
    
    voteDisplay.init();
    voteDisplay.setTopics( "apples", "oranges" );
    
    overlayGUI = new ofxUISuperCanvas( "OVERLAYS", 0, 0, 200, 200 );
    overlayGUI->addToggle( "DRAW CRAWL", &crawl.visible );
    overlayGUI->addSlider( "FONT SIZE", 8.0, 64.0, &crawl.fontSize );
    overlayGUI->addSlider( "CRAWL SPEED", 1.0, 20.0, &crawl.crawlSpeed );
    overlayGUI->addSpacer();
    overlayGUI->addToggle( "DRAW VOTING", &voteDisplay.visible );
    overlayGUI->addSlider( "VOTING MIN SCALE", 0.0, 1.0, &voteDisplay.minScale );
    overlayGUI->addSlider( "VOTING MAX SCALE", 0.0, 2.0, &voteDisplay.maxScale );
    // text input for overlay text
    overlayGUI->addSpacer();
    overlayGUI->addToggle( "DRAW TITLE", &textOverlay.visible );
    overlayGUI->addSlider( "TITLE SCALE", .5, 5.0, &textOverlay.fontScale );
    overlayGUI->addTextInput( "TEXT 1", "input text" )->setAutoClear( false );
    overlayGUI->addTextInput( "TEXT 2", "input text" )->setAutoClear( false );
    overlayGUI->addTextInput( "TEXT 3", "input text" )->setAutoClear( false );
    overlayGUI->addTextInput( "TEXT 4", "input text" )->setAutoClear( false );
    overlayGUI->addTextInput( "TEXT 5", "input text" )->setAutoClear( false );
    
    vector<string> images;
    images.push_back( "* 1280x720-FeelTV-Logo-01.png" );
    images.push_back( "* dog.png" );
    overlayGUI->addToggle( "DRAW OVERLAY", &drawOverlayImage );
    overlayGUI->addSlider( "OVERLAY OPACITY", 0.0, 1.0, &overlayImageOpacity );
    overlayGUI->addDropDownList( "OVERLAY IMAGE", images );
    overlayImage.loadImage( images[0].substr(2,images[0].length()-2) );
    
    
    overlayGUI->setColorBack( ofColor::grey );
    overlayGUI->autoSizeToFitWidgets();
    overlayGUI->loadSettings( "GUI/overlay.xml" );
    ofAddListener( overlayGUI->newGUIEvent, this, &Overlay::overlayGuiEvent );
}

void Overlay::update() {
    crawl.update();
    voteDisplay.update();
}

void Overlay::draw() {
    
    if ( drawOverlayImage ) {
        ofPushStyle();
        ofEnableBlendMode( OF_BLENDMODE_ALPHA );
        ofSetColor( 255, (int)(255*overlayImageOpacity) );
        overlayImage.draw( 0, 0 );
        ofPopStyle();
    }
    
    crawl.draw();
    voteDisplay.draw();
    textOverlay.draw();
}

void Overlay::overlayGuiEvent( ofxUIEventArgs &e ) {
    string name = e.widget->getName();
    if ( name.substr(0,2) == "* " )
        overlayImage.loadImage( name.substr( 2, name.length()-2 ) );
    
    if ( name.substr(0,4) == "TEXT" ) {
        ofxUITextInput *textinput = (ofxUITextInput *) e.widget;
        if( textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_ENTER ) {
            string output = textinput->getTextString();
            textOverlay.text = output;
        }
    }
}