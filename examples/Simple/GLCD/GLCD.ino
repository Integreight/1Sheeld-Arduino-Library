#define CUSTOM_SETTINGS
#define INCLUDE_GLCD_SHIELD
#include <OneSheeld.h>

// House
GLCDRectangle House(60,50,70,87,0);
GLCDRectangle HouseWindow1(65,60,25,15,0);
GLCDRectangle HouseWindow2(100,60,25,15,0);
GLCDRectangle HouseDoor(85,90,20,37,0);
GLCDLine HouseDoorHand(102,109,104,109);
GLCDLine HouseRoofLine1(60,50,95,15);
GLCDLine HouseRoofLine2(130,50,95,15);

// Sun
GLCDEllipse Sun(0,0,30,30);
GLCDLine SunLight1(35,8,56,13);
GLCDLine SunLight2(33,15,55,25);
GLCDLine SunLight3(30,22,50,38);
GLCDLine SunLight4(25,29,42,46);
GLCDLine SunLight5(20,35,36,54);
GLCDLine SunLight6(13,37,25,58);
GLCDLine SunLight7(7,39,15,61);

// Boy
GLCDLine BoyBody(150,100,150,118);
GLCDLine BoyLeftArm(150,104,160,110);
GLCDLine BoyRightArm(150,104,140,110);
GLCDLine BoyLeftLeg(150,118,154,126);
GLCDLine BoyRightLeg(150,118,146,126);
GLCDEllipse BoyHead(150,95,5,5);

// Girl
GLCDEllipse GirlHead(190,95,5,5);
GLCDLine GirlBody(190,100,190,112);
GLCDLine GirlLeftArm(190,104,200,110);
GLCDLine GirlRightArm(190,104,180,110);
GLCDLine GirlJupeLeftLine(190,112,196,120);
GLCDLine GirlJupeRightLine(190,112,184,120);
GLCDLine GirlJupeHorizontalLine(184,120,196,120);
GLCDLine GirlLeftLeg(188,120,188,126);
GLCDLine GirlRightLeg(192,120,192,126);
//Girl Hair
GLCDLine GirlHairLine1(190,90,194,87);
GLCDLine GirlHairLine2(190,90,186,87);
GLCDLine GirlHairLine3(186,87,185,90);
GLCDLine GirlHairLine4(194,87,195,90);
GLCDLine GirlHairLine5(190,90,192,84);
GLCDLine GirlHairLine6(190,90,188,84);
GLCDLine GirlHairLine7(188,84,182,87);
GLCDLine GirlHairLine8(192,84,198,87);

// Cloud
GLCDEllipse Cloud(200,20,30,10);

// First Bird
GLCDLine Bird1RightWing(155,20,150,17);
GLCDLine Bird1LeftWing(155,20,160,17);
// Second Bird
GLCDLine Bird2RightWing(140,15,135,12);
GLCDLine Bird2LeftWing(140,15,145,12);
// Third Bird
GLCDLine Bird3RightWing(210,40,205,37);
GLCDLine Bird3LeftWing(210,40,215,37);

void setup() {
// put your setup code here, to run once:
OneSheeld.begin();
GLCD.clear();
// call "drawScreen()" function to draw all shapes.
drawOnScreen();
}

void loop() {
// put your main code here, to run repeatedly:
}

void drawOnScreen()
{
    GLCD.draw(House);
    GLCD.draw(HouseWindow1);
    GLCD.draw(HouseWindow2);
    GLCD.draw(HouseDoor);
    GLCD.draw(HouseDoorHand);
    GLCD.draw(HouseRoofLine1);
    GLCD.draw(HouseRoofLine2);
    
    GLCD.draw(Sun);
    GLCD.draw(SunLight1);
    GLCD.draw(SunLight2);
    GLCD.draw(SunLight3);
    GLCD.draw(SunLight4);
    GLCD.draw(SunLight5);
    GLCD.draw(SunLight6);
    GLCD.draw(SunLight7);
    
    GLCD.draw(BoyBody);
    GLCD.draw(BoyRightArm);
    GLCD.draw(BoyLeftArm);
    GLCD.draw(BoyLeftLeg);
    GLCD.draw(BoyRightLeg);
    GLCD.draw(BoyHead);
    
    GLCD.draw(GirlBody);
    GLCD.draw(GirlRightArm);
    GLCD.draw(GirlLeftArm);
    GLCD.draw(GirlLeftLeg);
    GLCD.draw(GirlRightLeg);
    GLCD.draw(GirlHead);
    GLCD.draw(GirlJupeLeftLine);
    GLCD.draw(GirlJupeRightLine);
    GLCD.draw(GirlJupeHorizontalLine);
    GLCD.draw(GirlHairLine1);
    GLCD.draw(GirlHairLine2);
    GLCD.draw(GirlHairLine3);
    GLCD.draw(GirlHairLine4);
    GLCD.draw(GirlHairLine5);
    GLCD.draw(GirlHairLine6);
    GLCD.draw(GirlHairLine7);
    GLCD.draw(GirlHairLine8);
    
    GLCD.draw(Cloud);
    
    GLCD.draw(Bird1RightWing);
    GLCD.draw(Bird1LeftWing);
    GLCD.draw(Bird2RightWing);
    GLCD.draw(Bird2LeftWing);
    GLCD.draw(Bird3RightWing);
    GLCD.draw(Bird3LeftWing);
}
