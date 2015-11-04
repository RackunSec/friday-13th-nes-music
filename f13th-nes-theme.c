#include <Tone.h>
/* Friday the 13th Cabin Theme -
   Designed by Douglas Berdeaux.
   WeakNetLabs@Gmail.com

                           ############################
                          ##############################
                          ##         >. .v.           ##
                          ##       '_---VoV---_       ## 
                          ##      ' o         o ;     ##
                          ##     ` o           o '    ##
                          ##     . o   o   o   o .    ##
                          ##   __.      ___      _    ##
                          ##  '*>. o00o. - .o00o <*'  ## 
                          ##   `|  `00'     `00'  |   ##
                          ##    .                .    ##
                          ##    `  .  .  o  .  . '    ##
                          ##     . o   o   o   o.     ##
                          ##     `     o   o    '     ##
                          ##      `    o   o   '      ##
                          ##        `   _ _           ##
                          ##            `-            ##
                          ##############################
                           ############################
                           
                           */


Tone tone1;
Tone tone2;
int part1[] = {740,494,587}; // lead sections
int part2[] = {659,466,554};
int part3[] = {659,440,554};
int part4[] = {622,440,523};
int part5[] = {622,415,523};
int part6[] = {554,392,466};
int part6b[] = {554,415,523};
int part7[] = {466,392,440}; // the bridge
// dancing with Jason at the ball <3
int part8[] = {784,392,523,698,392,523};
int part9[] = {698,392,466,622,392,466};
int part10[] = {622,349,415,587,349,415};
int part11[] = {587,311,392,523,311,392};

//int bass[] = {247,233,220,262,208,196,208,196,173,156}; // MID bass sections
// int bass[] = {123,116,110,131,104,98,104,98,87,78}; // LOW bass sections
int bass[] = {122,116,110,131,104,98,104,98,87,78,156,92}; // LOW bass sections

void setup(void)
{
  tone1.begin(13);
  tone2.begin(12);
  
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);
}

void loop(){
  int buttonState = digitalRead(2);
  if(buttonState == HIGH){
    for(int i=1;i<=3;i++){
      //verse1(0);
      verse(1);
      bridge();
      ball();
    }
  }
}

void bridge(void){
 playSection(part7,5,4,3);
 playSection(part7,13,4,3);
 //delay(100);
}

void ball(void){ // ball dancing, merry go-round.
  playSection(part8,6,1,6);
  playSection(part9,7,1,6);
  playSection(part10,8,1,6);
  playSection(part11,9,1,6); 
  playSection(part8,6,1,6);
  playSection(part9,7,1,6);
  playSection(part10,8,1,6);
  playSection(part11,10,1,6); 
}

void verse(int last){ // first verse
    playSection(part1,0,2,3); // melody array, bass, repeat #
    playSection(part2,1,2,3);
    playSection(part1,0,2,3);
    playSection(part2,1,2,3);
    playSection(part3,2,2,3);
    playSection(part4,3,2,3);
    playSection(part5,4,2,3);
    if(last==0){
      playSection(part6,5,2,3); 
    }else{
     playSection(part6b,11,2,3); 
    }
}

void playSection(int notes[],int bassNote,int repeat,int length){ // play notes 
   for(int j=0;j<repeat;j++){
      if(bassNote != 13){ 
        tone2.play(bass[bassNote],(length - 1 * 300)); // TODO: calculate how long to play bass
      }
     for(int i=0;i<=length-1;i++){

      tone1.play(notes[i]);
      delay(300);
      tone1.stop(); 
    }
   tone2.stop(); 
  }  
}
