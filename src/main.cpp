#include <Arduino.h>
#include <SD.h>
#include <SPI.h>
#include <TFT.h>

// pin definition for Arduino UNO
#define sd_cs 4
#define cs 10
#define dc 9
#define rst 8

// create an instance of the library
TFT TFTscreen = TFT(cs, dc, rst);

PImage image;

void setup() {
    // initialize the library
    TFTscreen.begin();

    // clear the screen with a black background
    TFTscreen.background(0, 0, 0);
    // set the text size
    TFTscreen.setTextSize(2);

    Serial.begin(9600);

    if (!SD.begin(sd_cs)) {
        Serial.println("SC card dont detected!");
        return;
    }
    Serial.println("SC card detected successfully!");

    image = image.loadImage("nature1.bmp");

    while (!image.isValid()) {
        Serial.println("Loading image ......");
        delay(1000);
    }

    Serial.println("Image loaded successfully!!!");
}

void loop() {
    TFTscreen.background(0, 0, 0);

    // generate a random color
    int redRandom = random(0, 255);
    int greenRandom = random(0, 255);
    int blueRandom = random(0, 255);

    // set a random font color
    TFTscreen.stroke(redRandom, greenRandom, blueRandom);

    // print Hello, World! in the middle of the screen
    TFTscreen.text("Hello, World!", 6, 57);

    // wait 200 miliseconds until change to next color
    delay(3000);

    Serial.println("Try to drow image");

    TFTscreen.background(0, 0, 0);

    // draw the image to the screen
    int x = random(TFTscreen.width() - image.width());
    int y = random(TFTscreen.height() - image.height());
    TFTscreen.image(image, x, y);

    delay(3000);
}