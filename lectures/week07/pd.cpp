/*------------------------------------------------------------
 * pd.cpp	-	a reverse-engineering of 
 * Garry Vass' "The Pleasure Dome", DOMEGAME.COM.
 * Created by T. tek3@cox.net
 * Wed Apr 11 12:09:17 PDT 2012
 I did my best to contact Garry before I began to re-create
 his game, but never received an answer.  Much split-second 
 transitional material is different, but the design, text, 
 and colors are pretty close to the PC-DOS original.
 This was written for the Easter Vacation Open House at
 Grossmont College in San Diego.  It ran on the Buffy server
 at 209.129.16.61.
Wed Dec 17 12:48:58 PST 2014
Changed cheats:
fvatyr-fgrc vf 'z'
fvatyr-fgrc pna or rkcerffrq nf "z AA" gb tb eb abbz AA
pbzznaq gb vzzrqvngryl jva tnzr vf "uneevrg"
Added "quit" to exit quickly.
 ------------------------------------------------------------*/
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
//#include <boost/assign/std/vector.hpp> /* for "+=" string op */
#include "/var2/local/include/getchne.h"
#include "sloprint.h"
//#define NOFILE
#define ORGSPL   /* original spelling of all strings */
//#define harriet "singular"
//#define harriet "smiley"
//#define harriet "library"
//#define harriet "fnord"
#define harriet "harriet"
#define bail "quit"

using namespace std ;
//using namespace boost::assign ; /* for "+=" string op */
#undef TRACE   /* ifdef: no cls */

#define TRUE !0
#define FALSE !TRUE
int LINELENGTH = 60 ;

const int NUMROOMS = 26 ; 

int hint1viewed = 0 ;
int hint2viewed[7] = {0} ;
int spell_spoken = 0 ;

vector <string> dome1  ;

void prep_dome1(void)
{
dome1.push_back(        "        .***|||***.        ");
dome1.push_back(        "     .***   THE  *** .     ");
dome1.push_back(        "   .**   PLEASURE    **.   ");
dome1.push_back(        "  ***      DOME       ***  ");
dome1.push_back(        " **                     ** ");
dome1.push_back(        "**[][][][][][][][][][][][**");
dome1.push_back(        "**[][][][][][][][][][][][**")  ;

} // prep_dome1


vector <string> roomname (NUMROOMS)  ;
void prep_roomname()
{
roomname[0] =	"PROF HARRISBURG`S CATTERY " ;
roomname[1] =	"THE PLEASURE DOME`S GRAND ENTRANCE HALL " ;
	#ifdef ORGSPL
roomname[2] =	"A MOST ELEQUENT DINING ROOM " ;
	#else
roomname[2] =	"A MOST ELEGANT DINING ROOM " ;
	#endif
roomname[3] =	"MIGUEL`S PRIVATE LIBRARY " ;
roomname[4] =	"THE POWDER ROOM " ;
roomname[5] = 	"MIGUEL`S KITCHEN " ;
roomname[6] =	"THE MASTER BEDROOM " ;
roomname[7] =	"THE NETWORK CONTROL FACILITY " ;
roomname[8] =	"THE PLEASURE DOME`S MASTER CONTROL CENTER " ;
roomname[9] = 	"THE BALCONY, OVERLOOKING UNION CITY, NEW JERSEY " ;
roomname[10] =	"THE BALCONY, OVERLOOKING NORTH BERGEN, NEW JERSEY " ;
roomname[11] =	"THE BALCONY, OVERLOOKING HOBOKEN, NEW JERSEY " ;
roomname[12] =	"THE BALCONY, OVERLOOKING MANHATTAN, NEW YORK " ;
roomname[13] =	"THE BOTTOM OF A STAIRWELL " ;
roomname[14] = "THE TOP OF A STAIRWELL " ;
roomname[15] = "A SPOOKY, CREAKY ATTIC " ;
roomname[16] =	"A DANK AND MUSKY BASEMENT " ;
roomname[17] =	"THE BATTLEMENT TOWER " ;
roomname[18] =	"MIGUEL`S SECRET DUNGEON " ;
roomname[19] =	"THE UPSTAIRS WATER CLOSET " ;
roomname[20] =	"THE GRAND BALLROOM " ;
roomname[21] =	"THE MINOR BALLROOM " ;
roomname[22] =	"A SECRET PASSAGEWAY " ;
roomname[23] =	"THE ROUND ROOM JUST UNDER THE TOP OF THE PLEASURE DOME " ;
roomname[24] =	"A NON-SECRET PASSAGEWAY " ;
roomname[25] =	"THE PORTRAIT ROOM "  ;
} // prep_roomname

vector <string> line3(NUMROOMS) ;
void prep_line3()
{
line3[0]=	"FOUR HUGE CATS REGARD YOU SLEEPILY";
	#ifdef ORGSPL
line3[1]=	"THERE ARE TWO FERETS PLAYING IN THE CORNER";
	#else
line3[1]=	"THERE ARE TWO FERRETS PLAYING IN THE CORNER";
	#endif
line3[2]=	"THERE ARE SEVERAL MUSHROOMS IN A WOODEN BOWL";
line3[3]=	"YOU CAN HEAR A SOFT, SWEET VIOLIN";
line3[4]=	"THE AROMA OF ROSES REFRESHES YOU";
line3[5]=	"YOU CAN HEAR SOMEONE LAUGHING";
line3[6]=	"A MAGNIFICENT PORTRAIT OF MIGUEL HANGS ON THE WALL";
line3[7]=	"THERE IS A GLOW EMANATING FROM THE FLOOR";
line3[8]=	"THERE ARE DOZENS OF CROSSWORD PUZZLES STREWN ABOUT";
line3[9]=	"IT IS VERY QUIET HERE";
line3[10]=	"THERE IS A PRICELESS PERSIAN CARPET HERE (THINK!)";
line3[11]=	"FROM FLOOR TO CEILING, THERE ARE THOUSANDS OF DISKETTES HERE";
line3[12]=	"YOU SEE A TINY CRACK IN THE WALL";
line3[13]=	"THERE IS AN ENCHANTED MIRROR HERE";
line3[14]=	"THERE ARE SEVERAL PIECES OF MAGIC FRUIT HERE";
line3[15]=	"THERE IS A CURSED HELMET LAYING ON THE FLOOR";
	#ifdef ORGSPL
line3[16]=	"THERE IS AN ANNOITED FLAIL AT YOUR FEET";
	#else
line3[16]=	"THERE IS AN ANNOINTED FLAIL AT YOUR FEET";
	#endif
line3[17]=	"YOU SPY AN ELFIN SWORD OF ANCIENT ORIGIN";
line3[18]=	"THERE IS A BLUE CRYSTAL BALL HERE";
line3[19]=	"YOU CAN SMELL GASOLINE HERE";
line3[20]=	"THERE IS A PAINTING OF A COTTAGE HERE";
line3[21]=	"THERE IS AN ENGRAVED AMULET HERE";
line3[22]=	"YOU SEE A LARGE GREEN SNAKE EYEING YOU";
line3[23]=	"MIGUEL`S SUNGLASSES SIT QUIETLY IN THE CORNER";
line3[24]=	"THERE IS GRAFITTI ON THE WALL";
line3[25]=	"THERE IS A SILVER PLATTER HERE"  ;
} // prep_line3

vector <string> spells (27) ;
void prep_spells() 
{
spells[0] = "WOOTER , FLEA , SIAMESE, SAM , MAINE-COON , SEALPOINT";
spells[1] = "NIX , ALCHEMY , ART , BRUJERIA , CANTRIP , CONJURATION";
spells[2] = "CRAFT, DIVINATION, ENCHANTMENT, OT, WEEHAWKEN, FAIRY, JADU";
spells[3] = "JUJU, LEGERDEMAIN, PI, MANA, MAYA, OBEAH, POWER, CHI";
spells[4] = "RITE, RUNE, SHAMANISM, PEREZ, SORCERY, ALF, SORTILEGE";
spells[5] = "SUPERNATURAL, MUM, TALISMAN, STYX, THAUMATURGY, THEURGY";
spells[6] = "VOODOO, RED, GHOLA, MALEFICE, VASS, BULLET, CHARM, MASCOT ";
spells[7] = "NE, MERRYTHOUGHT, PERIAPT, SILVER, LIN, SCARAB, WISHBONE";
spells[8] = "SESAME, CIRCE, BAR, HECATE, POLICE STATION, GYGES, UR, ARROWROD";
spells[9] = "ATHOS, CATALINA, MU, CADUCEUS, RHABDOS, CRC, WINDWALKER";
spells[10] = "BABRAXAS, YIN, ROTHENBBS, CARACT, NU, DUNCAN, PENTACLE, ABRACADABRA";
spells[11] = "MO, HOCUSPOCUS, PRESTO, SELAH, ROSS, SESAME, BEWITCH";
spells[12] = "GOETIC, LETO, YAN, ZI, ARCHMAGE, SHAMAN, PURPLE, CIRCEAN";
spells[13] = "LEVEL 8 THIEF, WIZARD, FI, LIX, ROMA, WONDER, CUNJAH, GWYDION";
spells[14] = "HOUDINI, ISANGOMA, JUGGLER, DIP, KOSCHEI, MAGE, MAGUS";
spells[15] = "PHI, MANDRAKE, MERLIN, MUNDUNUGU, RX, OBEAHDOCTOR";
spells[16] = "OBEAHMAN, BLUE, OMEGAMMON, TOR, WABENO, KY, WESTERMAN, WANGATEUR";
spells[17] = "ZOUNDS, PROFONDE, UTHER, ZA, COSIMA, RICHARD, GOLD, WAGNER";
spells[18] = "TRISTAN, QYNX, AUREOLE, BRAVERY, BRILLIANCE, GJV, FLARE";
spells[19] = "GLORY, HALO, LUSTER, BA, LUXURY, MAJESTY, GYN, NIMBUS";
spells[20] = "RHO, NOBILITY, PARADE, POMP, HONORIFIC, CHARISMA" ;
spells[21] = "SOVEREIGN, CAOBA, TABASCO, PYL, THE BOSS, MELANGE, GAWAIN";
spells[22] = "IX, SONGBIRD, GWYN, ORION, KYN, AMAZON, BLISS, CHARM";
spells[23] = "WOTAN, ESTE, RON, DELIGHT, DESIRE, XI, OPULENCE, BENE";
spells[24] = "MECHAIEH, OK, MIRTH, GARRY, WONDER, ZEST, MMP, HARKONNEN";
spells[25] = "DUNE, ADHAKA, NY, DANDA, LAMANY, NYX, OUROUB, JAWS, TOLA" ;
spells[26] = "FRIDA, MEEFIE, LORN, HASJARL, GRONK, TI, SANJIRMIL, SAM, FLANDERS" ;
} // prep_spells

//vector <string> feeling(NUMROOMS) ;
vector <string> feeling ;
void prep_feeling()
{
feeling.push_back(	"FURRY");
	#ifdef ORGSPL
feeling.push_back(	"HUNGARY");
	#else
feeling.push_back(	"HUNGRY");
	#endif
feeling.push_back(	"TIRED");
feeling.push_back(	"RAKISH");
feeling.push_back(	"SNIDE");
feeling.push_back(	"ADVENTUROUS");
feeling.push_back(	"AMOROUS");
feeling.push_back(	"SLUGGISH");
feeling.push_back(	"INQUISITIVE");
feeling.push_back(	"RIGHTEOUS");
feeling.push_back(	"CLEVER");
feeling.push_back(	"BOLD");
feeling.push_back(	"WEAK");
feeling.push_back(	"CANDID");
feeling.push_back(	"HAPPY");
feeling.push_back(	"MAJOR BACK PAINS");
feeling.push_back(	"YOUR OATS");
feeling.push_back(	"SENSITIVE");
feeling.push_back(	"PATRIOTIC");
feeling.push_back(	"LONELY");
feeling.push_back(	"LIKE A PATSY");
feeling.push_back(	"GOOD ABOUT LIFE");
feeling.push_back(	"DEAD SERIOUS");
feeling.push_back(	"CONFUSED");
feeling.push_back(	"ELATED");
feeling.push_back(	"FIND") ;
feeling.push_back(	"HERMETIC") ;
} ; 
	
vector <string> line4 ;
void prep_line4()
{
	//a note here says:
line4.push_back(	"CAT SCRATCH FEVER");
line4.push_back(	"WELL SHE WAS JUST SEVENTEEN, YOU KNOW WHAT I MEAN");
line4.push_back(	"I GOT SUNSHINE ON A CLOUDY DAY");
line4.push_back(	"SHE`S REAL FINE MY FOUR - OH - NINE");
line4.push_back(	"I KNOW YOU WANT TO LEAVE ME");
line4.push_back(	"I TOLD YOU ONCE AND I TOLD YOU TWICE");
line4.push_back(	"SOME USELESS INFORMATION SUPPOSED TO TRY MY IMAGINATION");
line4.push_back(	"IT`S YOUR 19TH NERVOUS BREAKDOWN");
line4.push_back(	"SAID SHE`LL HAVE FUN FUN FUN");
line4.push_back(	"ROUND, ROUND, GET AROUND, I GET AROUND");
line4.push_back(	"DUKE, DUKE, DUKE, DUKE OF EARL, DUKE, DUKE");
line4.push_back(	"GO ASK ALICE, WHEN SHE`S TEN FEET TALL");
line4.push_back(	"BABY I NEED YOUR LOVIN''");
line4.push_back(	"LEFT A GOOD JOB IN THE CITY");
line4.push_back(	"BAREFOOT GIRLS SITTING ON THE HOOD OF A DODGE");
line4.push_back(	"HOW MANY ROADS MUST A MAN WALK DOWN");
line4.push_back(	"TOOK A WALK PAST YOUR HOUSE, LATE LAST NIGHT");
line4.push_back(	"STAY, JUST A LITTLE BIT LONGER");
line4.push_back(	"YOU NEVER CLOSE YOUR EYES WHEN I KISS YOUR LIPS");
line4.push_back(	"HEAVENLY SHADES OF NIGHT ARE FALLING");
line4.push_back(	"I WALK FORTY SEVEN MILES OF BARBWIRE");
line4.push_back(	"LET`S SWIM TO THE MOON, UH HUH, LET`S CLIMB TO THE TIDE");
line4.push_back(	"THIS IS THE END, BEAUTIFUL FRIEND, THE END");
line4.push_back(	"OH HO WE YES, I`M THE GREAT PRETENDER, AH OOH AH OOH");
line4.push_back(	"SHOTGUN, SHOT `EM WHILE THE RUN NOW");
line4.push_back(	"MY TEMPERATURE`S RISING AND MY FEVER IS UP" ) ;
} ;

vector <string> crown1 ;
void prep_crown1()
{
crown1.push_back(" O            O           _O ");
crown1.push_back(" |\\\\        //#\\\\        //|)");
crown1.push_back(" | \\\\      ///I\\\\\\      // |)");
crown1.push_back(" |  \\\\    ////# \\\\\\    //  |)");
crown1.push_back(" |   \\\\  /////   \\\\\\  //   |)");
crown1.push_back("  |    \\\\/////     \\\\\\//    |)");
crown1.push_back(" |VVVVV\\/VVVVVVVVVVV\\/VVVVV|)");
crown1.push_back("  |YYYYYYYYYYYYYYYYYYYYYYYYYY)" ) ;
} 

vector <string> burning_question ;
void prep_burning_question()
{
burning_question.push_back(	"PYEWACKETT?");
burning_question.push_back(	"DEUCES, JACKS, AND THE KING WITH THE  ?" );
burning_question.push_back(	"INCENSE AND ?" );
burning_question.push_back(	"KING OF THE JUNGLE?" );
burning_question.push_back(	"WHO IS JOHN GALT?" );
burning_question.push_back(	"BUGS BUNNY`S VOICE?" );
burning_question.push_back(	"SUPERBOY`S DOG?" );
burning_question.push_back(	"KILROY WAS ?" );
burning_question.push_back(	"WHAT`S GREY AND COMES IN QUARTS?" );
burning_question.push_back(	"*ONE TWO THREE FOUR, WE DON`T WANT YOUR ? ?" );
burning_question.push_back(	"R-C COLA AND A ?" );
burning_question.push_back(	"ROCKY TOP, ?" );
burning_question.push_back(	"SLEEPY, SNEEZY, DOPEY, GRUMPY, DOC, BASHFUL, AND ?" );
burning_question.push_back(	"HUEY, DEWEY, AND ?" );
burning_question.push_back(	"ENTERPRISE HELMSMAN?" );
burning_question.push_back(	"JIMMY DODD AND BIG ?" );
burning_question.push_back(	"EDITH, ARCHIE, GLORIA, AND ?" );
burning_question.push_back(	"MARY, TED, LOU, AND ? AND ?" );
burning_question.push_back(	"PANAMA ?" );
burning_question.push_back(	"BATMAN`S BUTLER?" );
burning_question.push_back(	"NURSE ON THE ENTERPRISE?" );
burning_question.push_back(	"HAWKEYE, RADAR, HOOLAHAN, AND ? AND ?" );
burning_question.push_back(	"ROCKY`S PET TURTLES?" );
burning_question.push_back(	"BEHIND THE GREEN ?" );
burning_question.push_back(	"LUCY, RICKY, ETHEL, AND ?" );
burning_question.push_back(	"GOMER`S BROTHER?" ) ;
}

vector <string> copyright  ;
void prep_copyright()
{
	copyright.push_back(	"\"****  PLEASE DO NOT ALTER THIS PROGRAM ****");
	copyright.push_back(	"****  IT HURTS ALL OF US WHEN SOMEBODY DOES THAT  ****");
	copyright.push_back(	"****  IF YOU WANT A PROGRAM PLUGGING YOUR BOARD, JUST ASK ME ****");
	copyright.push_back(	"AND I WILL SET ONE UP FOR YOU FREE OF CHARGE -\"");
	copyright.push_back(	"ORIGINAL DESIGNER:  GARRY J. VASS");  
	copyright.push_back(	"                                                         ");   
	copyright.push_back(	"THIS C++ UNIX VERSION OF DOMEGAME WAS WRITTEN BY");   
	copyright.push_back(	"T. HARRISBURG: tek3@cox.net" );   
	copyright.push_back(	"ALL TEXT STRINGS ARE UNCHANGED FROM THE ORIGINAL BINARY." );   
	copyright.push_back(	"DOMEGAME WAS MY FIRST MS-DOS COMPUTER GAME IN 1986." );
}     
	
vector <string> strings2  ;
void prep_strings2()
{
strings2.push_back("A GLITTERING CROWN!!");
//strings2.push_back("\"YOUR CROWN, SIR\"");
strings2.push_back("\"YOUR CROWN, SIR!!\"");
strings2.push_back("ALL YOUR NEW FOUND FRIENDS:  THE AMULET, THE SNAKE, THE");
#ifdef ORGSPEL
strings2.push_back("MIRROR, THE FERETS, AND THE REST, COME BACK TO LIFE AND");
#else
strings2.push_back("MIRROR, THE FERRETS, AND THE REST, COME BACK TO LIFE AND");
#endif
strings2.push_back("GATHER AROUND YOU, SLAPPING YOUR BACK AND CONGRATULATING");
#ifdef ORGSPEL
strings2.push_back("YOU.  THE VIOLIN BREAKS OUT A BOTTLE OF LAFITTE (`48),");
//strings2.push_back("POURS A ROUND, AND EVERYONE HAS A DAMN JOLLY GOOD TIME!!") ;
strings2.push_back("POURS A ROUND, AND EVERYONE HAS A JOLLY GOOD TIME!!") ;
#else
strings2.push_back("YOU.  THE VIOLIN BREAKS OUT A BOTTLE OF LAFITE `48,");
strings2.push_back("POURS A ROUND, AND EVERYONE HAS A JOLLY GOOD TIME!!") ;
#endif
} 

vector < string > dome3  ;
void prep_dome3()
{
	//dome3.push_back("-----------------------------------------------------------------"); 
	dome3.push_back("-----------------------------------------------------------------"); 
	dome3.push_back("-----------------------------------------------------------------");
	dome3.push_back("TO TRAVEL, TYPE YOUR SPELL HERE --> ") ;
} 

vector <string> hint1 ;
void prep_hint1()
{
//hint1.push_back(	"Y OR N?" );
hint1.push_back(	"TO YOUR AMAZEMENT, THE FRUITS STAND UP AND SING: " );
hint1.push_back(	"OH, BRAVE SOUL!  OH WANDERING KNIGHT!" );
hint1.push_back(	"OH, PRINCE OF ADVENTURE, THE TIME IS RIGHT!" );
hint1.push_back(	"MASTER THIS MAZE, CONQUER THESE SPELLS," );
	#ifdef ORGSPL
hint1.push_back(	"LEARN OF THIER SECRETS, AND THE STORY EACH TELLS!" );
	#else
hint1.push_back(	"LEARN OF THEIR SECRETS, AND THE STORY EACH TELLS!" );
	#endif
hint1.push_back(	"THE QUEST YOU HAVE JOINED AND PERILS YOU FACE," );
hint1.push_back(	"CAN NOT BE MET WITH SWORD, AXE, OR MACE." );
hint1.push_back(	"NO TREASURES AWAIT YOU IN SOME GUARDED ROOM," );
hint1.push_back(	"NO COAL MINES, NO WELLS, AND NO RAMSES` TOMB." );
hint1.push_back(	"AS PROOF OF THE TRUTH THAT THESE WORDS BE," );
hint1.push_back(	"A HINT (BELOW) IS OFFERED TO THEE..." );
hint1.push_back(	"JUST STRIKE A KEY." );
hint1.push_back(	"ALL NUMBERS ARE LUCKY, ALL ROOMS ARE TRUE," );
hint1.push_back(	"THE RELATION BETWEEN THEM IS IMPORTANT TO VIEW," );
hint1.push_back(	"ODDLY ENOUGH, AND EVEN A FEW," );
hint1.push_back(	"JUST WATCH THEM CLOSELY, THIS IS YOUR CLUE." );
hint1.push_back(	"STRIKE A KEY DO..." ); 
hint1.push_back(	"YOU SEE SOME FRUIT DROPPINGS" ) ;
} 

std::vector< std::vector < string > > doors (28) ; // must dimension array or seggault:
//TODO: not equal to numrooms, nore to 28, re=examine the room strings in the original .com file
// there are only 17 rooms programmed here.
void prep_doors()
{
doors[0].push_back("6                                                      ");
doors[0].push_back("6                                                      ");
doors[0].push_back("6                                                      ");
doors[0].push_back("6                                                      ");
doors[0].push_back("6          _______________                             ");
doors[0].push_back("6         |               |                            ");
doors[0].push_back("6         |       _       |                            ");
doors[0].push_back("6         |      |_|      |                            ");
doors[0].push_back("6         |               |                            ");
doors[0].push_back("6         |               |                            ");
doors[0].push_back("6         |  O            |                            ");
doors[0].push_back("6         |               |                            ");
doors[0].push_back("6         |               |                            ");
doors[0].push_back("6         |               |                            ");
doors[0].push_back("6         |               |                            ");
doors[0].push_back("6         |               |                            ");
doors[0].push_back("6                                                      ");
doors[0].push_back("6                                                      ");
doors[0].push_back(" YOU SEE A MYSTERIOUS DOOR...                          ");
doors[0].push_back(" <-- THIS IS YOU                                       ");
#ifdef ORGSPEL
doors[0].push_back("YOU GO BOLDY WHERE NO MAN HAS GONE BEFORE              ");
#else
doors[0].push_back("YOU GO BOLDLY WHERE NO MAN HAS GONE BEFORE             ");
#endif
doors[0].push_back("YOU OPEN THE DOOR                                      ");
doors[0].push_back("YOU STEP INSIDE...                                     ");
doors[0].push_back("THE PLEASURE DOME                                      ");
doors[0].push_back("  <---  ") ;

doors[1].push_back("AS A GREEN MIST ENVELOPES YOU, THE SNAKE HISSES,  ");
doors[1].push_back("\"CARE FOR A GAME OF CRAPS?\"  HE THEN CHUCKLES IN A");
doors[1].push_back("MANNER THAT RAISES THE HAIRS ON THE BACK OF YOUR  ");
doors[1].push_back("NECK.  THE SPELL FINALLY TAKES HOLD AND YOU       ");
doors[1].push_back("DISAPPEAR IN A STATE OF CONFUSION.                ");
doors[1].push_back("HIT ANY KEY");

doors[2].push_back("THE SNAKE LIES SLEEPING, COILED AROUND A PAIR OF DICE");
doors[2].push_back("  <--  ") ;

doors[3].push_back("AS A BRONZE MIST ENVELOPES YOU, THE VIOLIN SUDDENLY");
doors[3].push_back("BREAKS INTO A WILD JIG WHICH YOU CORRECTLY IDENTIFY");
doors[3].push_back("AS BEING A SOUTH AMERICAN ADAPTATION OF \"GREEN GROW");
doors[3].push_back("THE LILACS\".  ENGULFED BY THE MIST, YOU TRAVEL ON. ");
doors[3].push_back("GRAB ANY KEY") ;

doors[4].push_back("A SHATTERED VIOLIN IN THE CORNER MEETS YOUR DUMBSTRUCK GAZE");

doors[5].push_back(" ");
#ifdef ORGSPEL
doors[5].push_back("AS A PINK MIST SWALLOWS YOU, THE FERETS WHISPER    ");
#else
doors[5].push_back("AS A PINK MIST SWALLOWS YOU, THE FERRETS WHISPER    ");
#endif
doors[5].push_back("TOGETHER EXCITEDLY.  ONE OF THEM TURNS TO YOU AND  ");
doors[5].push_back("SAYS, \"YOU HAVE BEEN HERE BEFORE, YOU KNOW.  JUST  ");
doors[5].push_back("REMEMBER THIS:  WHAT GOES AROUND COMES AROUND.\"    ");
doors[5].push_back("GRAB ANY KEY") ;

doors[6].push_back(	" " );
		#ifdef ORGSPEL
doors[6].push_back("THE FERETS EYE YOU EXPECTANTLY");
		#else
doors[6].push_back("THE FERRETS EYE YOU EXPECTANTLY");
		#endif
doors[6].push_back("AS A RUDDY VAPOR SWELLS ABOUT YOU, THE ROSES SIGH AND  ");
doors[6].push_back("WHISPER, \"AH, IF ONLY WE COULD BE AS EPHEMERAL AS A    ");
doors[6].push_back("LUCKY NUMBER.  THEN WE WOULD NEVER WILT AND DIE.  BUT  ");
doors[6].push_back("PERHAPS LUCKY NUMBERS ALSO HAVE A CORPOREAL EXISTENCE.\"");
doors[6].push_back("EAGER TO LEARN MORE, YOU STRAIN AGAINST THE SPELL, BUT ");
doors[6].push_back("TO NO AVAIL...                                         ");
doors[6].push_back("TOUCH A KEY" ) ;

doors[7].push_back(" " );
doors[7].push_back("THE ROSES YOU ONCE SAW HERE ARE GONE");
doors[7].push_back("AS A CLEAR VAPOR SWELLS ABOUT YOU, THE MIRROR SIGHS AND");
doors[7].push_back("SPEAKS, \"IN A BEAUTIFUL CASTLE AT THE EDGE OF A WOOD, ");
doors[7].push_back("AS THE QUEEN`S CONSORT, I ONCE PROUDLY STOOD. ");
doors[7].push_back("BUT VANITY, VANITY, SUCH A DEAR COST,");
doors[7].push_back("BEAUTY LASTS FOR A MOMENT, THEN IT IS LOST.");
doors[7].push_back("SO LISTEN, BRAVE KNIGHT, AND HEAR WHAT I TELL ");
doors[7].push_back("AS BEAUTY GOES, THE CLUES GO AS WELL,");
doors[7].push_back("ONE FLASH OF THE EYE, LIKE THE LIFE OF A PAWN,");
doors[7].push_back("YOU SEE THEM JUST ONCE, THEN THEY ARE GONE.\" ");
doors[7].push_back("TOUCH A KEY") ;

doors[8].push_back(" ");
doors[8].push_back("A CRACKED AND SILENT MIRROR REFLECTS YOUR INTENSE GAZE");
doors[8].push_back("  /\\_|-|_^^II_|=|");

doors[9].push_back("AS A BLUEISH SPRAY OVERWHELMS YOU, THE SKY OVER THE");
doors[9].push_back("BIG APPLE LIGHTS UP IN A DAZZLING DISPLAY OF FIREWORKS.");
doors[9].push_back("STRANGELY, THE DISPLAY COALESCES TO FORM A MESSAGE");
doors[9].push_back(		"WHICH READS, \"IGNORE ANYTHING WRITTEN IN PURPLE, IT IS");
doors[9].push_back(		"THERE ONLY TO CONFUSE YOU.\"  THE SKY THEN BECOMES DARK");
doors[9].push_back(		"AND YOU ARE UNABLE TO READ MORE.                       ");
doors[9].push_back(		"TOUCH A KEY") ;
	
doors[10].push_back(" " );
doors[10].push_back("THE SKYLINE IS DARK");
doors[10].push_back("  |#|K|#|P|#|#|T|");
doors[10].push_back("  ---------------");
doors[10].push_back("  |R|#|B|L|U|E|#|");
doors[10].push_back("  ---------------");
doors[10].push_back("  |E|#|#|E|#|#|P|");
doors[10].push_back("  ---------------");
doors[10].push_back("  |D|R|A|M|B|U|I|");

doors[11].push_back("AS A GREYISH SPRAY OVERWHELMS YOU, YOU NOTICE THAT     ");
doors[11].push_back("SOMEONE HAS CIRCLED THE CLUE FOR `25 ACROSS`.  THE CLUE");
doors[11].push_back("READS, \"ACCRUAL\".  AS YOU REACH FOR THE PUZZLE, THE    ");
doors[11].push_back("SPELL REACHES FOR YOU.  ANOTHER ANNEX OF THE PLEASURE  ");
doors[11].push_back("DOME AWAITS YOUR ARRIVAL.                              ");
doors[11].push_back("TOUCH A KEY" ) ;
	
doors[12].push_back(" " );
doors[12].push_back("?THE CROSSWORD PUZZLES YOU ONCE SAW HERE ARE NOW A PILE OF ASHES");
doors[12].push_back("       ^        ");
doors[12].push_back("        I        ");
doors[12].push_back("        I        ");
doors[12].push_back("        I        ");
doors[12].push_back("      [-I-]      ");
doors[12].push_back("        I        ");
doors[12].push_back("        U        ");

doors[13].push_back("AS A SILVER CLOUD GATHERS YOU, THE SWORD SMILES AND    ");
doors[13].push_back("SAYS \"BLESSINGS TO YOU, NOBLE SEARCHER, BRAVE SQUIRE! ");
doors[13].push_back("MAY YOUR EYES ALWAYS BE SHARP,                         ");
doors[13].push_back("MAY YOUR WILL NEVER TIRE.                              ");
doors[13].push_back("THE NUMBERS BRING LUCK, BE THEY LOWER OR HIGHER,       ");
doors[13].push_back("AND REMEMBER ONE THING:  THE SNAKE IS A LIAR!!\"       ");
doors[13].push_back("TOUCH A KEY")  ;
	
doors[14].push_back(" " );
doors[14].push_back("A BROKEN LIGHT SABER (WITH DEAD BATTERIES) LIES AT YOUR FEET");

doors[15].push_back("     __i__      ");
doors[15].push_back("     //` `\\\\     "); // tek3 4/16/15
doors[15].push_back("     !o   o!     ");
doors[15].push_back("     !  ~  !     ");
doors[15].push_back("     !==O==!     ");
doors[15].push_back("      \\___/      ");
doors[15].push_back("                 ");
doors[15].push_back("THE CURSED HELMET (ENTIRELY UNOCCUPIED) ANSWERS YOUR   ");
doors[15].push_back("SPEECHLESS STARE WITH A SCRATCHY, METALIC VOICE:       ");
doors[15].push_back("\"DIG, DUG, BED, BUG, RED, RUG,");
doors[15].push_back("FIG, HUG, JIG, JUG, TUG, LUG,");
doors[15].push_back("LAX, SAX, MAX, RAX, BAX, HAX,");
doors[15].push_back("TOR, SOR, NOR, VOR, GOR, EOR,");
doors[15].push_back("CAST THEM ONE, CAST THEM ALL,");
doors[15].push_back("FROM BEDROOM, KITCHEN, CLOSET AND HALL,");
doors[15].push_back("LOOK NOT SO MUCH AT THE SPELL YOU CALL,");
doors[15].push_back("BUT INTO IT (THAT IS ALL)!!!!");
doors[15].push_back("TOUCH A KEY") ;
	
doors[16].push_back(" " );
doors[16].push_back("(AN UNIDENTIFIABLE PIECE OF METAL IS HERE");
doors[16].push_back("     +        ");
doors[16].push_back("   __/ \\__     ");
doors[16].push_back("   \\  *  /     ");
doors[16].push_back("   /\\   /\\     ");
doors[16].push_back("__/  \\_/  \\__  ");
doors[16].push_back("# UM-TUT-SUT # ");
doors[16].push_back("#------------# ");
doors[16].push_back("YOU ARE STARTLED AS THE AMULET BEGINS A SOFT, BUT      ");
doors[16].push_back("FETCHING, INCANTATION.                                 ");
doors[16].push_back("\"HOLD HERE A WHILE, OH KNIGHT BRAVE AND FREE,         ");
doors[16].push_back("FOR ON MY FACE A SYMBOL DOTH BE,                    ");
doors[16].push_back("REMEMBER ME WELL, AND NOTE WHAT YOU SEE,            ");
doors[16].push_back("I`LL CALL FOR IT LATER AS PART OF THE KEY!\"         ");
doors[16].push_back("HIT RETURN" ) ;

#ifdef ORGSPL
doors[17].push_back("DID YOU BELEIVE THE SNAKE?");
#else
doors[17].push_back("DID YOU BELIEVE THE SNAKE?");
#endif
} ;
	
vector < string > trans2 (27) ;

void prep_trans2() 
{ 
trans2[0]=	"TRANSITIONAL MAGIC ENERGY WELLS UP AROUND" ;  // TEK3: not in original game??
trans2[1]=	"THERE ARE SOME AMULET DROPPINGS HERE" ;
trans2[2]=	"FIND THE AMULET, SHE IS WAITING WITH A MESSAGE" ;
trans2[3]=	"FIND THE SNAKE, BUT DON`T LISTEN TO HIM" ;
trans2[4]=	"THE SWORD CAN TELL YOU SOMETHING" ;
trans2[5]=	"TRY AND FIND THE VIOLIN NEXT" ;
trans2[6]=	"THINK MUSHROOM !!!" ;
trans2[7]=	"THINK FLOWERS" ;
trans2[8]=	"READ THE GRAFITTI" ;
trans2[9]=	"FIND THE ROSES" ;
trans2[10]=	"YOU CAN SEE FIREWORKS FROM THE BALCONY" ;
trans2[11]=	"FIND THE MIRROR" ;
	#ifdef ORGSPL
trans2[12]=	"DID YOU KNOW THAT SOME FERETS CAN TALK?" ;
	#else
trans2[12]=	"DID YOU KNOW THAT SOME FERRETS CAN TALK?" ;
	#endif
trans2[13]=	"YOU NEED TO FIND THE CRYSTAL BALL" ;
trans2[14]=	"THERE IS A HELMET WAITING AROUND HERE SOMEWHERE" ;
trans2[15]=	"LOOK FOR A BOWL OF FRUIT NOW !" ;
trans2[16]=	"THE RUG DOES NOT TALK" ;
trans2[17]= "PAY ATTENTION WHEN YOU SEE THE CROSSWORD PUZZLES" ;
trans2[18]=	"CHECK THE BALCONY" ;
trans2[19]=	"FIND THE PLATTER" ;
trans2[20]=	"WOP WOP WOP, WOP WOP ADABA ADABA" ;
trans2[21]=	"DO WAH DO WAH DO DUP DITTY" ;
trans2[22]=	"DON`T GET CAUGHT BY A RED HERRING!" ;
trans2[23]=	"PLEASE IGNORE MY LAST" ;
trans2[24]=	"JUST PEEK UNDER THE RUG" ;
trans2[25]=	"GIVE THE CANDY TO THE SNAKE" ;
	#ifdef ORGSPL
trans2[26]=	"IT SHOULD BE COMMING TO YOU BY NOW" ;
	#else
trans2[26]=	"IT SHOULD BE COMING TO YOU BY NOW" ;
	#endif
} // prep_trans2


std::vector< std::vector < string > > hint2 (8) ;
//std::vector< std::vector < string > > hint2  ;
void prep_hint2()
{
hint2[0].push_back(	"YOU NEED TO");
hint2[0].push_back(	"COUNT ");
hint2[0].push_back(	"SOMETHING");
hint2[0].push_back(	"");
hint2[1].push_back(	"COUNT ");
hint2[1].push_back(	"THE ");
hint2[1].push_back(	"LETTERS");
hint2[1].push_back(	"");

hint2[2].push_back(	"THE");
hint2[2].push_back(	"LETTERS");
hint2[2].push_back(	"IN");
hint2[2].push_back(	"YOUR");
hint2[2].push_back(	"SPELL");
hint2[2].push_back(	"");

hint2[3].push_back(	"THE");
hint2[3].push_back(	"LUCKY");
hint2[3].push_back(	"NUMBER");
hint2[3].push_back(	"");

	//hint2[4] +);
hint2[4].push_back(	"LUCKY");
hint2[4].push_back(	"NUMBER");
hint2[4].push_back(	"=");
hint2[4].push_back(	"ROOM");
hint2[4].push_back(	"NUMBER");
hint2[4].push_back(	"");

hint2[5].push_back(	"VISIT");
hint2[5].push_back(	"ALL");
hint2[5].push_back(	"THE");
hint2[5].push_back(	"ROOMS");
hint2[5].push_back(	"THEN");
hint2[5].push_back(	"GIVE");
hint2[5].push_back(	"MAGIC");
hint2[5].push_back(	"SPELL");
hint2[5].push_back(	"");

hint2[6].push_back(	"MAGIC");
hint2[6].push_back(	"SPELL") ;

} // prep_hint2

std::vector< std::vector<string> > trans (27)  ;
void prep_trans()
{
	trans[0].push_back( "AS YOU TAKE SHAPE YOU FEEL THE URGE TO SNEEZE FROM THE CAT FUR") ;

	trans[1].push_back("AS YOU ARE JUST BEGINNING TO MATERIALIZE, THE VISION OF");
	trans[1].push_back("A BEAUTIFUL SIREN/TEMPTRESS/MYNX/SHE-GOAT PASSES BEFORE");
	trans[1].push_back("YOUR DAZZLED EYES.  THROUGH THE MIST, SHE SEEMS TO");
	trans[1].push_back("BE WHISPERING SOMETHING TO YOU. " );
	trans[1].push_back("YOU THINK YOU HEAR THE WORDS:");
	trans[1].push_back("A KEY PLEASE..." );

	trans[2].push_back("    ____    ~`` ");
	trans[2].push_back("    ( o  )  ~~~  ");
	trans[2].push_back("   <___\\__>      ");
	trans[2].push_back("      []         ");
	trans[2].push_back("      []         ");
	trans[2].push_back("      []         ");
	trans[2].push_back("      []         ");
	trans[2].push_back("AS YOU RIGHTFULLY EXPECTED, A SEDATE CATEPILLAR APPEARS");
	trans[2].push_back("ATOP THE LARGEST MUSHROOM.  IT ADDRESSES YOU:          ");
	trans[2].push_back("\"AS YOUR SPELL DOES ITS WORK WITH ITS MAGICAL FORCE,   ");
	trans[2].push_back("YOU CAN SEE YOURSELF MOVING ALONG A SET COURSE.        ");
	trans[2].push_back("THE DIRECTION AND COLOR OF THE LITTLE SUNBEAMS,        ");
	trans[2].push_back("ARE A PLEASURE TO WATCH AND HAVE MEANING IT SEEMS.     ");
	trans[2].push_back("BUT OH, SO IMPORTANT FOR THIS MAZE TO UNRAVEL,         ");
	trans[2].push_back("IS NOT THE TIME, NOR THE DISTANCE,                     ");
	trans[2].push_back("BUT THE LENGTH OF YOUR TRAVEL.\"                       ");
	trans[2].push_back("HIT RETURN");

	trans[3].push_back("THERE IS AN EMPTY BOWL HERE");
	trans[3].push_back("   ________     ");
	trans[3].push_back("   C\\       \\    ");
	trans[3].push_back("   \\C\\   G   \\   ");
	trans[3].push_back("    \\C\\   J   \\  ");
	trans[3].push_back("     \\C\\   V   \\ ");
	trans[3].push_back("      \\C\\_______\\");
	trans[3].push_back("       \\C | | | |");
	trans[3].push_back("THE PLATTER, A RELIC BROUGHT BACK FROM THE PUNIC WARS  ");
	trans[3].push_back("BY AN IRISH MERCENARY (WHOSE NAME HAS BEEN LOST IN THE ");
	trans[3].push_back("MISTS OF TIME), REFLECTS YOUR STUDIED GLARE WITH A     ");
	trans[3].push_back("PATIENCE HONED BY EONS OF NEGLECT.  SLOWLY, YOUR       ");
	trans[3].push_back("REFLECTION IN THIS ANTIQUE TREASURE MELTS INTO A SOFT  ");
	trans[3].push_back("GOLDEN HUE.  THIS IN TURN SLOWLY MELTS INTO AN IMAGE OF");
	trans[3].push_back("A GIANT SANDWORM.  THIS IMAGE CHANGES BY DEGREES TO AN ");
	trans[3].push_back("IMAGE OF A GIANT, ALIEN TOWER AT THE END OF A RIVER.   ");
	trans[3].push_back("FINALLY, YOU SEE A CARAVAN OF ELEVENTH CENTURY         ");
	trans[3].push_back("CRUSADERS IN FULL ARMOR.  EACH HAS SAINT GEORGE`S CROSS");
	trans[3].push_back("EMBLAZENED ON HIS TUNIC.   \"WILL YOU PLEASE LEAVE ME   ");
	trans[3].push_back("ALONE NOW?\" THE PLATTER DEMANDS RUDELY.                ");
	trans[3].push_back("HIT RETURN");

	#ifdef ORGSPEL
	trans[4].push_back("THERE IS A TANISHED PLATTER HERE WISHING YOU WOULD LEAVE") ;
	#else
	trans[4].push_back("THERE IS A TARNISHED PLATTER HERE WISHING YOU WOULD LEAVE") ;
	#endif 

	trans[5].push_back("                ");
	trans[5].push_back("                 ");
	trans[5].push_back("      \\ | /      ");
	trans[5].push_back("      - O -      ");
	trans[5].push_back("      / | \\      ");
	trans[5].push_back("                 ");
	trans[5].push_back("                 ");
	#ifdef ORGSPEL
	trans[5].push_back("THE SECRET VOYEUR IN YOU FORCES YOU TO PEEK IN SIDE THE");
	#else
	trans[5].push_back("THE SECRET VOYEUR IN YOU FORCES YOU TO PEEK INSIDE THE ");
	#endif
	trans[5].push_back("CRYSTAL BALL.  YOU SEE A MAN IN A BATHROOM WITH A      ");
	trans[5].push_back("ROBOT.  THE ROBOT APPEARS TO BE COMPLAINING ABOUT SOME-");
	trans[5].push_back("THING, BUT YOU CAN`T HEAR IT.  SUDDENLY, THE SCENE     ");
	trans[5].push_back("CHANGES TO A RESTAURANT WITH MASSIVE PICTURE WINDOWS.  ");
	trans[5].push_back("THE SCENE CHANGES AGAIN AND YOU SEE MILLIONS OF CHINESE");
	trans[5].push_back("ACCOUNTANTS LABORING AWAY OVER MILLIONS OF CHINESE     ");
	trans[5].push_back("ABACI.  AS YOUR MIND NEARLY GRASPS THIS CLUE, YOU ARE  ");
	trans[5].push_back("PULLED AWAY.                                           ");
	trans[5].push_back("HIT RETURN");


	trans[6].push_back("THERE IS AN EMBARASSED CRYSTAL BALL HERE");

	trans[7].push_back("                ");
	trans[7].push_back("      X#X#X      ");
	trans[7].push_back("      #X#X#      ");
	trans[7].push_back("      X#X#X      ");
	trans[7].push_back("      #X#X#      ");
	trans[7].push_back("      X#X#X      ");
	trans[7].push_back("                 ");
	trans[7].push_back("THE RUG HIDES A TRAP DOOR.  THE TRAP DOOR LEADS TO A   ");
	trans[7].push_back("DAMP CAVE WHERE YOU CAN FACE BOUNDLESS ADVERSITY AND   ");
	trans[7].push_back("COLLECT ALL SORTS OF EXOTICA.  BUT THAT`S A DIFFERENT  ");
	trans[7].push_back("STORY.  THE RUG CAN ALSO BE USED TO FLY, AND WOULD BE  ");
	trans[7].push_back("HANDY IF YOU NEEDED TO SAVE A PRINCESS.  BUT THAT`S A  ");
	trans[7].push_back("DIFFERENT STORY ALSO.   IF FACT THE ONLY CLUE HERE     ");
	trans[7].push_back("IS IN THE PICTURE OF THE RUG ITSELF.                   ");
	trans[7].push_back("HIT RETURN");

	trans[8].push_back( "SOMEONE FLEW OFF ON THE CARPET, SOMEONE ELSE STOLE THE TRAP DOOR");

	trans[9].push_back( "THE GAS FUMES CAUSE YOU TO LOSE YOUR BEARINGS  ");
	trans[9].push_back("FOR JUST A MINUTE.  YOU PULL YOURSELF TOGETHER.");

	trans[10].push_back( "YOU SMELL NOTHING");

	trans[11].push_back("AS A GOLDEN MIST SWELLS ABOUT YOU, THE GRAFITTI BECOMES");
	trans[11].push_back("READABLE.  YOU ARE ABLE TO MAKE OUT SEVERAL PHRASES.   ");
	trans[11].push_back("...MOVING ABOUT...CAN BE CONTROLLED...SPELLS...");
	trans[11].push_back("SIMPLY...<EXPLETIVE DELETED>...THEN DETERMINE...");
	trans[11].push_back("...GET THE...AND...WILL BE...YOUR DESTINATION...");
	trans[11].push_back("...<SIGNED>...GARRY J. VASS");
	trans[11].push_back("TOUCH A KEY");

	trans[12].push_back("THE GRAFITTI YOU ONCE SAW HERE HAS BEEN ERASED");

	trans[13].push_back("THIS SPACE FOR RENT");

	trans[14].push_back("A HOLLOW VOICE SAYS, \"DID YOU BRING YOUR `INVISICLUES`?\", AND GUFFAWS.");

	trans[15].push_back("IT IS PITCH BLACK HERE");

	trans[16].push_back("A HOLLOW VOICE SAYS, \"PLUGH\", AND TITTERS.");

	trans[17].push_back("YOU SEE A SIGN READING \"N J TURNPIKE - 1 MILE\"");

	trans[18].push_back("A HOLLOW VOICE SAYS, \"ASK THE CONDOR\", AND LAUGHS.");

	trans[19].push_back("YOU ARE BEGINNING TO GET HUNGRY");

	trans[20].push_back("A HOLLOW VOICE SAYS, \"TILTOWAIT\", AND GIGGLES.");

	trans[21].push_back("THE SPELL, ");
	trans[21].push_back("SWEEPS YOU AWAY...");
	trans[21].push_back("(AGAIN)");

	trans[22].push_back("TRUE");
	trans[22].push_back("FALSE");
	trans[22].push_back("-=*> ") ;

	trans[23].push_back("THE SPELL, ");
	trans[23].push_back("SWEEPS YOU AWAY...");
	trans[23].push_back("(AGAIN)");

	trans[24].push_back("THE SPELL, ");
	trans[24].push_back("SWEEPS YOU AWAY...");
	trans[24].push_back("(AGAIN)");

	trans[25].push_back("THE SPELL, ");
	trans[25].push_back("SWEEPS YOU AWAY...");
	trans[25].push_back("(AGAIN)");
} // prep_trans

char menu[][80] = {
{"YOU ARE IN"}, 
{" <*=-"}, 
#ifdef ORGSPL
{"YOUR ARE FEELING"}, 
#else
{"YOU ARE FEELING"}, 
#endif
{"A NOTE HERE SAYS:"}, 
{"+THE INFORMATION GIVEN IN THE LAST ROOM WAS"}, 
{"BURNING QUESTION: "}, 
{"SPELLS YOU CAN CAST IN THIS ROOM ARE "},
{"THE LUCKY NUMBER HERE IS"}} ;

vector < string > invalidspell ;
void prep_invalidspell()
{
	invalidspell.push_back("I V L D  P L !!");
	invalidspell.push_back(" N A I  S E L!!") ;
}

vector < string > crownprompt  ;
void prep_crownprompt()
{
	crownprompt.push_back("        =        ");
	crownprompt.push_back("     __/ \\__     ");
	crownprompt.push_back("     \\  *  /     ");
	crownprompt.push_back("     /\\   /\\     ");
	crownprompt.push_back("  __/  \\_/  \\__  ");
	crownprompt.push_back("  # UM-TUT-SUT # ");
	crownprompt.push_back("  #------------# ");
	crownprompt.push_back("WHAT`S THIS ?!?  YOUR FRIEND THE AMULET HAS REAPPEARED!");
	crownprompt.push_back("SHE IS TALKING, SO LET`S LISTEN IN...");
	crownprompt.push_back("\"GREETINGS FAIR SIR, I BID YOU HELLO,");
	crownprompt.push_back("THE TIME IS AT HAND TO SEE WHAT YOU KNOW.");
	crownprompt.push_back("HAVE YOU MASTERED THE SPELLS?");
	crownprompt.push_back("CAN YOU TRAVEL AT WILL?");
	crownprompt.push_back("OR DOES THE PLEASURE DOME`S SECRET");
	crownprompt.push_back("ELUDE YOU AND BAFFLE YOU STILL?");
	crownprompt.push_back("A TEST NOW IS NEEDED FOR YOU TO BE TRIED.");
	crownprompt.push_back("A SPELL I WILL CONJURE, A SPELL I WILL HIDE");
	crownprompt.push_back("IS NOW BEING ADDED TO ALL ROOMS INSIDE.");
	crownprompt.push_back("THOUGH IT`S NOT LISTED, OR GIVEN TO VIEW,");
	crownprompt.push_back("CAST THIS ONE SPELL, MY TRAVELER TRUE,");
	crownprompt.push_back("AND THE PLEASURE DOME`S CROWN SHALL BE GIVEN TO YOU!");
	crownprompt.push_back("HIT RETURN");
} // prep_crownprompt


vector < string > instructions ;
vector < string >  splashscreen ;
vector < string >  rank ;
vector <string> hack_error ;
void prep_instructions()
{
	instructions.push_back("THIS IS AN UNUSUAL TYPE OF ADVENTURE GAME, NO ONE GETS     " ); 
	instructions.push_back("KILLED, NO VALUABLE TREASURES ARE TAKEN, AND MAPS CANNOT   " ); 
	instructions.push_back("BE DRAWN <BY THE TRADITIONAL METHOD ANYWAY>.               " ); 
	instructions.push_back("                                                           " ); 
	instructions.push_back("YOU MOVE ABOUT AND CAUSE THINGS TO HAPPEN BY CASTING SPELLS." );
	instructions.push_back("                                                            " );
	instructions.push_back("AT LEAST ONE THING THAT MUST BE DONE TO CLAIM VICTORY INSIDE" );
	instructions.push_back("THE PLEASURE DOME IS TO VISIT ALL THE PLACES.  OTHER THINGS" );
	instructions.push_back("WILL BE REVEALED TO YOU IN YOUR TRAVELS.  MANY THINGS YOU" );
	instructions.push_back("WILL SEE AND HEAR ARE DISTRACTIONS." );
	instructions.push_back("THIS IS T. Harrisburg's RE-WRITE OF GARRY J. VASS'" );
	instructions.push_back("ORIGINAL, USING THE ORIGINAL TEXT STRINGS." );
	instructions.push_back("   " );
	instructions.push_back("     \"In Xanadu, did Kubla Khan a stately pleasure dome decree,     ") ;
	instructions.push_back("     Where Alf, the sacred river ran,     ") ;
	instructions.push_back("     Through caverns measureless to man,     ") ;
	instructions.push_back("     Down to a sunless sea.\"     ") ;
	instructions.push_back("");
	instructions.push_back("GOOD LUCK INSIDE THE PLEASURE DOME!!");
	instructions.push_back("-=>HIT A KEY<=-"  );

	splashscreen.push_back("INSIDE THE PLEASURE DOME");
	splashscreen.push_back("BROUGHT TO YOU BY THE PLEASURE DOME BBS");
	splashscreen.push_back("( 201 - 330 - 0613 )" );
	splashscreen.push_back("  " );
	splashscreen.push_back("  " );
	splashscreen.push_back("  " );
	splashscreen.push_back("  " );
	splashscreen.push_back("  " );
	splashscreen.push_back("WOULD YOU LIKE INSTRUCTIONS?");
	splashscreen.push_back("Y/N");

	rank.push_back("FORGET IT!" ) ;
	rank.push_back("STABLE BOY" ) ;
	rank.push_back("JUNIOR SQUIRE" ) ;
	rank.push_back("SENIOR SQUIRE" ) ;
	rank.push_back("KNIGHT OF THE REALM" ) ;
	rank.push_back("LORD AND PEER" ) ;

	hack_error.push_back("CIRCUITS") ;
	hack_error.push_back("INFORM") ;
	hack_error.push_back("THAT") ;
	hack_error.push_back("SOMEONE") ;
	hack_error.push_back("HAS") ;
	hack_error.push_back("ALTERED") ;
	hack_error.push_back("THIS") ;
	hack_error.push_back("PROGRAM ") ;
	hack_error.push_back("I CANNOT") ;
	hack_error.push_back("CONTINUE") ;
} // prep_instructions

char  div1[] = {"=============================================="} ;

char endit[][80] = { {"YOU HAVE PLAYED INSIDE THE PLEASURE DOME`"}, } ;


char randomstrings[][80] = {
{"YOUR RANK IS..."},
{"____                    _____"},
{"    \\____HIT A KEY_____/     "},
{"         \\_______/           "},
{"THE PLEASURE DOME BBS"},
{"NORTH BERGEN, NEW JERSEY"},

{"NOITDADERNAYC"},
{"GYIt"},
{"(201 - 330 - 0613)"}} ;

void cls() { system("clear") ; }

void cprintf(const char * text , int back, int fore) // centers
{
	int i, len = LINELENGTH - strlen(text) ;
	len /= 2 ;
	for (i = 0 ; i < len ; i++) putchar(' ') ;

   //printf("\033[%2d;%2dm%s\033[0m",  back, fore, text) ;
   printf("\033[%2d;%2dm", back, fore) ;
	sloprint(text,3000) ;
	printf("\033[0m") ;
}

void cputs(const char * text , int back, int fore) // centers
{
   printf("\033[%2d;%2dm%s\033[0m",  back, fore, text) ;
}

void cputchar(const char * text , int back, int fore) // centers
{
	printf("\033[%2d;%2dm%s\033[0m",  back, fore, text) ;
}


/*
void cprintf(char *s, int color  )
{
   //echo -e $i $j "\033[${i};${j}mCOLOR\033[0m"
	int i, len = LINELENGTH - strlen(s) ;
	printf("%c[m", 033) ;
	len /= 2 ;
	for (i = 0 ; i < len ; i++)
		putchar(' ') ;
	printf("%s", s) ;
	printf("%c[m%c%c[0m", 033, color, 033) ;
	return 0 ;
} // cprintf ends
*/

/*----------------------------------------------------
*	later this will be an anti-hacking measure to keep
* 	users from modifying bytes in the executable
----------------------------------------------------*/
int check_bytes(char * name)
{
	char buf[90] ;
	unsigned long std = 156356UL, total ;
	FILE  * fp = fopen (name, "rb") ;
	if (!fp) return -1 ;
	fseek(fp, 0L,  SEEK_END) ; 
	total = ftell(fp) ;
	fclose(fp) ;
#ifdef TRACE
	printf("TRACE: total bytes in executable: %lu\n", total) ;
	printf("TRACE: standard bytes in executable: %lu\n", std) ;
#endif
	if (std != total)
	{
		sprintf(buf, "original bytes: %lu now: %lu\n", std, total) ;
		hack_error.push_back(buf) ;
		//cprintf(buf, 39, 41) ;
		for (unsigned int i = 0 ; i < hack_error.size() ; i++)
		{
			sprintf(buf, "%s\n", hack_error[i].c_str() ) ;
			cprintf(buf, 39, 41) ;
		}
		exit(-1) ;
	}
	return 0 ; 
}  //check_bytes

bool won = 0 ;
int main(int argc , char * argv[])
{
	char buf[1024] ;
// record start of attempt:
#ifndef NOFILE
FILE * fp = fopen ("attempts", "a+") ;  // made local for demo code
if (fp != 0) {

	//struct tm * tm ;
	time_t timet1 ;
	//tm = localtime(&timet1) ; 
	memset(buf, 0 , sizeof(buf)) ;
	time(&timet1)           ;
	char *x = getenv("USER") ;
	sprintf(buf,"%-10s at %s", x, ctime(&timet1)) ;
	for (unsigned int i = 0 ; i < sizeof(buf) ; i++)
		if (buf[i] == '\n' || buf[i] == '\n') buf[i] = ' ' ;
	fprintf(fp, "%s\n", buf) ;
	fclose (fp) ;
}
else printf("cannot open attempt file") ;
#endif
	prep_roomname()         ;
	prep_dome1()            ;
	prep_dome3()            ;
	prep_hint1()            ;
	prep_hint2()            ;
	prep_roomname()         ;
	prep_line3()            ;
	prep_spells()           ;
	prep_feeling()          ;
	prep_line4()            ;
	prep_crownprompt()      ;
	prep_crown1()           ;
	prep_burning_question() ;
	prep_copyright()        ;
	prep_strings2()         ;
	prep_doors()            ;
	prep_trans()            ;         
	prep_trans2()           ; 
	prep_instructions()     ;
	prep_invalidspell()     ;
	//check_bytes(argv[0])  ;  //DON'T ENABLE: RELIC ONLY (works)
	/*---------------------------------------------------
	*	program begins
	---------------------------------------------------*/
	char * bp ;
	/*--------------------------------------------------
	*	if program segfaults, add 
	*		export LINES
	*		export COLUMNS
	*		to your .bash_profile config
	--------------------------------------------------*/
	LINELENGTH = atoi(getenv("COLUMNS") ) ;
   //int ROWS = atoi(getenv("LINES")) ;
   int COLS = LINELENGTH ;
	int spell_length  ;
	// record of which rooms user has visited:
	int visited[NUMROOMS] = {0} ;
	int current_room = 0 ; // was 1
	visited[0] = 1 ;
	int i, j, c ;
	// start program, offer instructions.
	intro:
	#ifndef TRACE
	cls() ;
	printf("\n") ;
	#endif
	/*---------------------------------------------------
	*	splash screen
	---------------------------------------------------*/
	for (unsigned int i = 0 ;  i < doors[0].size() ; i++) 
	{
		sprintf(buf,"%s\n", doors[0][i].c_str()) ;
		cprintf(buf, 36, 40) ;
	}
	fflush(stdin) ;
	c = getchne() ;
	cls() ; 
	printf("\n") ;
	for (unsigned int i = 0 ;  i <  splashscreen.size() ; i++)
	{
		sprintf(buf,"%s\n", splashscreen[i].c_str()) ; 
		cprintf(buf, 36, 40) ;
	}
	c = getchne() ;
	#ifndef TRACE
	cls() ;
	printf("\n") ;
	#endif
	/*---------------------------------------------------
	*	show help
	---------------------------------------------------*/
	if (toupper(c) == 'Y')
	{
	#ifndef TRACE
	cls() ;
	printf("\n") ;
	#endif
		for (unsigned int i = 0 ;  i < instructions.size() ; i++)
		{
			sprintf(buf,"%s\n", instructions[i].c_str()) ;
			cprintf(buf, 37, 49) ;
		}
		//cprintf("key: ", 37, 49) ;
		getchne() ;
		//cls() ;
		goto intro ;
	} // if toupper
	/*---------------------------------------------------
	*	main loop
	---------------------------------------------------*/
	// begin main loop 
	memset(buf,0, sizeof(buf)) ;
	/*---------------------------------------------------
	*	first room
	---------------------------------------------------*/
	#ifndef TRACE
	cls() ;
	printf("\n") ;
	#endif
	//show first door
	current_room = 0 ; 
	//printf("current room: %d\n", current_room) ;
	printf("\n") ;
	//for (unsigned int i = 0 ;  i < doors[0].size() ; i++) 
	//{
	//	sprintf(buf,"%s\n", doors[0][i].c_str()) ;
	//	cprintf(buf, 36, 40) ;
	//}
	//getchne() ;

	/*---------------------------------------------------
	*	enter rooms
	---------------------------------------------------*/
rooms:
	do
	{
		// see if all rooms have been visited yet:
		won = 1 ;
			for (i = 1 ; i < NUMROOMS ; i++)
				if( visited[i] == 0) 
					won = 0 ;

		// begin main game display
		#ifndef TRACE
			cls() ;
			printf("\n") ;
		#endif
		// display dome header
		// This is probably not random in the original game: research TODO
		int r =  ( current_room + (10000 * rand()) ) % trans.size();
		r = current_room ;
		int tr = r % trans.size() ;
		for (unsigned i = 0 ; i < trans[tr].size() ; i++)
		{
			sprintf(buf,"%s\n", trans[tr][i].c_str() ) ;
			cprintf(buf, 32, 40) ;
		}
	getchne() ;  // TODO: REMOVE?
	#ifndef TRACE
		cls() ;
		printf("\n") ;
	#endif
	r = current_room ;
	printf("\n") ;
	if ( 0 == visited[current_room])
	{
		for ( unsigned i = 0 ; i < doors[r].size()  ; i++)
		{
			sprintf(buf,"%s\n", doors[r][i].c_str() ) ;
			//cprintf(buf, 34, 42) ; // green overwash
			//cprintf(buf, 32, 40) ;
			cprintf(buf, 39, 49) ;
		}
		getchne() ;
	}
	visited[current_room] = 1 ; 
	#ifndef TRACE
		printf("\n") ;
		cls() ;
		printf("\n") ;
	#endif
	for ( unsigned i = 0 ; i < dome1.size() ; i++)
	{
		sprintf(buf,"%s\n", dome1[i].c_str()) ;
		//cprintf(buf, 34, 42) ;
		cprintf(buf, 32, 49) ;
	}
	printf("\n") ; // blank line after dome

	bp = buf ; // start building line
//TEK
	bp += sprintf(bp,"--=*> YOU ARE IN %s<*=--", roomname[current_room].c_str()) ; 
	bp += 8 ;
		
	cprintf(buf, 36, 45) ; // actually print the constructed line
	bp = buf ; // reset character pointer

	cputs(" \n", 32, 49) ; // blank line after dome

	#ifdef ORGSPL
		sprintf(buf, "YOUR ARE FEELING: %s\n", feeling[current_room].c_str() ) ; 
	#else
		sprintf(buf, "YOU ARE FEELING: %s\n", feeling[current_room].c_str() ) ; 
	#endif
	cprintf(buf, 39, 40) ;
	sprintf(buf,"%s\n", line3[current_room].c_str()) ;
	cprintf(buf, 31, 49) ;
	sprintf(buf, "A NOTE HERE SAYS: %s\n", line4[current_room].c_str() ) ;
	cprintf(buf, 36, 49) ;
	if (current_room != 1 )
	{
		sprintf(buf, "THE INFORMATION GIVEN IN THE LAST ROOM WAS %s\n", 
			(1000 * rand()) % 2 ? "TRUE" : "FALSE") ;
		cprintf(buf, 35, 40) ;
	}
	else
		putchar('\n') ;
	sprintf(buf, "BURNING QUESTION: %s\n", burning_question[current_room].c_str()) ;// maybe an error
	cprintf(buf, 32, 40) ;

	cprintf("SPELLS YOU CAN CAST IN THIS ROOM ARE:\n", 31, 40) ;
	sprintf(buf,"%s\n", spells[current_room].c_str() ) ;  
	cprintf(buf, 31, 40) ;

	 if (current_room != 0 )
	{
		sprintf(buf, "YOUR LUCKY NUMBER HERE IS: %d\n", current_room) ;
		cprintf(buf, 36, 40) ;
	}
	
	// TRANS2
		sprintf(buf,"%s\n\n",trans2[current_room].c_str()) ; 
		cprintf(buf, 30, 46) ; //cprintf("Press-->", 37, 49) ;
		//getchne() ;
	
	//    receive user spell, 

	char spell_buf[254] ;
	for (unsigned int i = 1 ; i < dome3.size()-1 ; i++)
	{
		sprintf(buf,"%s", dome3[i].c_str() ) ;
		cprintf(buf, 30, 45) ;
		putchar('\n') ;
		//sprintf(buf,"TO TRAVEL, TYPE YOUR SPELL HERE: ") ;
		//cprintf(buf, 30, 45) ;
	}
	sprintf(buf,"%s", dome3[dome3.size() -1].c_str() ) ;
	cprintf(buf, 30, 45) ;
	/****************************************************
	INPUT SPELL WITH CONTROLLED ECHOING VIA getpass()
	****************************************************/
	fflush(stdin) ;
	memset(spell_buf,0,sizeof(spell_buf)) ;
	strncpy(spell_buf, getpass(" "), sizeof(spell_buf)) ;

	/***************************************************
	DON'T ECHO HINT OR harriet COMMANDS
	Sat Feb  2 20:34:21 PST 2013 fixed it to not show "hint"
	***************************************************/
	if (
	 	(strlen(spell_buf) != 1) && 
		(spell_buf[0] != 'm') && 
	(0 != strncmp( spell_buf , harriet, strlen(spell_buf)))  &&
	(0 != strncmp( spell_buf , "hint",   strlen(spell_buf))) &&
	(0 != strncmp(spell_buf, bail, strlen(spell_buf))))
	{
		int lead = (LINELENGTH - strlen(spell_buf)) / 2 ; 
		for ( int x = 0 ; x < lead ; x++)
			printf(" ") ;
		printf("%s\n", spell_buf) ;
		sleep(1) ;
	}

	/*****************************************************
	if backdoor is used....
	*****************************************************/
	if (strcasestr( spell_buf , harriet )) {
		for (int i = 0 ; i < NUMROOMS ; i++) {
			visited[i] = 1 ; won = 1 ;
		} goto won ;
	}

	if (strcasestr( spell_buf , bail )) {
		for (int i = 0 ; i < NUMROOMS ; i++) {
			return -1 ;	
		} goto won ;
	}
	/**************************************************
	VALIDATE MAGIC SPELL as real spell or one-room jump
	**************************************************/
	if( (strlen(spell_buf) != 1) && strcasestr(spells[current_room].c_str() , spell_buf) ) 
	{
		spell_length = strlen(spell_buf) ;
		current_room += spell_length ; 
		current_room %= 27 ; // pgm was aborting segfault w/ 25
	} //simple room change
	else
	if((spell_buf[0] == 'm') && spell_buf[1] == ' ' && isdigit(spell_buf[2]))
	{	
		string roomdigit;
		roomdigit.clear() ;
		roomdigit += spell_buf[2] ;
		roomdigit += spell_buf[3] ;
		current_room = atoi(roomdigit.c_str()) ;
	} // direct to a random room
	else
	if (( strlen(spell_buf) == 1 && spell_buf[0] == 'm'))
	{
		spell_length = strlen(spell_buf) ;
		current_room += spell_length ; current_room %= 27 ; // pgm was aborting segfault w/ 25
	} 
	else // VALIDATE REQUEST FOR A HINT 
	{
		if ( (strcasestr(spell_buf, "HELP")) ||
		(strcasestr(spell_buf, "HINT")) ) {
			if (hint1viewed == 0) {
				hint1viewed = 1 ; 
				for (unsigned int x = 0 ; x < hint1.size() ; x++) {
					sprintf(buf, "%s\n", hint1[x].c_str()) ; 
					cprintf(buf, 39, 41) ;
				} getchne() ;
			} // first hint not viewed?
			else // already seen hint1 
			{
				for (unsigned int q = 0 ; q < hint2.size() ; q++) {
					if (0 == hint2viewed[q]) {
						hint2viewed[q] = 1 ; 
						for (unsigned int x = 0 ; x < hint2[q].size() ; x++) {
							sprintf(buf, "%s\n", hint2[q][x].c_str()) ;
							cprintf(buf, 39, 41) ;
						} getchne()
						; break ;
						// only read one
					} // this one's not viewed yet
				} // process all hint2 text entries
			} // read hint2 member if possible
		} 
		else // NOT COMMAND, NOT HELP REQ, ERROR MSG 
		{
			sprintf(buf,"ERROR ERROR ERROR\n") ; 
			cprintf(buf, 39, 41) ; 
			sprintf(buf,"spell %s not found in: %s\n", 
			spell_buf, spells[current_room].c_str()) ;
			cprintf(buf, 39, 41) ;
			sprintf(buf,"Press -->") ; 
			cprintf(buf, 39, 41) ;
			fflush(stdin) ; getchne() ; 
			goto rooms ;
		} // error in command
	} // not a hint, then won: 
	if (1 == won) 
	{
		// now all rooms have been visited, so solicit the magic spell: 
	#ifndef TRACE
			cls() ;
	#endif 
		//sprintf(buf,"Oh Traveller, this is the most solemn moment:\n") ;
		//cprintf(buf, 33,49) ; 
		sprintf(buf,"Oh Traveller, this is the most solemn moment:\n") ;
		cprintf(buf, 33,49) ; 
		for (unsigned int i = 0 ; i < crownprompt.size() ; i++) 
		{
			sprintf(buf, "%s\n",
			crownprompt[i].c_str()) ;
			cprintf(buf, 33,49) ; sleep(1) ;
		} 
		getchne() ; 
		#ifndef TRACE 
		cls() ;
		#endif 
		sprintf(buf,"DO YOU KNOW THE FINAL SPELL?\n") ; 
		cprintf(buf, 33,49) ;
		cprintf("=", 33,49) ; strncpy(spell_buf, getpass(" "), sizeof(spell_buf)) ;
	// fgets(spell_buf, sizeof(spell_buf) -3, stdin) ;
		#ifndef TRACE 
			cls() ; 
			printf("\n") ; 
		#endif

			if (strcasestr(spell_buf, "MAGIC SPELL") )
			{
				spell_spoken = 1 ;	
			}
			else
			{
				for (unsigned int i = 0 ; i < invalidspell.size() ; i++)
				{
					sprintf(buf,"%s\n", invalidspell[0].c_str()) ; 
					cprintf(buf , 39, 41) ;
					sprintf(buf,"%s\n", invalidspell[1].c_str()) ; 
					cprintf(buf , 39, 41) ;
				}// for invalidspell
			} // else not magic spell
		} 
	} while (0 == won || 0 == spell_spoken ) ; // while not won both ways...main_loop
won:
	cls() ;
	// GAME IS WON: DISPLAY
   //printf("rows: %d columns: %d\n", ROWS, COLS) ;
   for ( j = 0 ; j < 4; j++)
   {
      for ( i = 0 ; i < COLS; i++)
      {
         cputchar(".", 34, 43) ;
      }
      putchar('\n') ;
		sleep(1) ;
   }
	for (unsigned int i = 0 ; i < strings2.size() ; i++)
	{
		sprintf(buf,"%s\n", strings2[i].c_str() ) ;
		cprintf(buf, 39, 41) ;
		sleep(1) ;
	}
	for (unsigned int i = 0 ; i < crown1.size() ; i++)
	{
		sprintf(buf,"%s\n", crown1[i].c_str() ) ;
		cprintf(buf, 33, 49) ;
		sleep(1) ;
	}
	printf("\n") ;

	sprintf(buf,"HOORAY!  YOU HAVE WON!\n") ;
	cprintf(buf, 39, 41) ;
	sleep(1) ;
	sprintf(buf, "Thanks to Garry J. Vass, and the Pleasure Dome BBS\n") ;
	cprintf(buf,39,41) ;
	sleep(1) ;
	sprintf(buf, "for the original game.  Unix C version written by \n") ;
	cprintf(buf,39,41) ;
	sleep(1) ;
	sprintf(buf, "T. Harrisburg, Easter 2012.\n") ;
	cprintf(buf,39,41) ;
	sleep(1) ;

	for ( unsigned i = 0 ; i < dome1.size() ; i++)
	{
		sprintf(buf,"%s\n", dome1[i].c_str()) ;
		cprintf(buf, 45, 37) ;
		sleep(1) ;
	}
	printf("\n") ;

   for ( j = 0 ; j < 4 ; j++)
   {
      for ( i = 0 ; i < COLS; i++)
      {
         cputchar(".", 34, 43) ;
      }
      putchar('\n') ;
		sleep(1) ;
   }
	char * USER = getenv("USER") ;
	printf("You are USER: %s\n", USER) ;
	sprintf(buf,"domegamewinners") ;  // made local for demo code

	struct tm * tm ;
	time_t timet1 ;
#ifndef NOFILE
	fp = fopen(buf, "a+") ;
	if (fp != 0) 
	{
		memset (buf, 0, sizeof(buf)) ;
		fflush(stdin) ;
		printf("Press a Key to see other winners:") ;
		getchne() ;
		printf("\n") ;
		fgets(buf, sizeof(buf)-1, fp) ;
		while ( !feof(fp))
		{
			printf("%s", buf) ;
			fgets(buf, sizeof(buf)-1, fp) ;
		}
	//struct tm * tm ;
	time_t timet1 ;
		tm = localtime(&timet1) ; 
		memset(buf, 0 , sizeof(buf)) ;
		time(&timet1)           ;
		//printf(buf,"%-10s at %s", USER, ctime(&timet1)) ;
		sprintf(buf,"%-10s at %s", USER, ctime(&timet1)) ;
		for (unsigned int i = 0 ; i < sizeof(buf) ; i++)
			if (buf[i] == '\n' || buf[i] == '\r') buf[i] = ' ' ;
		fprintf(fp,"%s\n", buf) ;
		printf("%s\n", buf) ;
		fclose(fp) ;
	}
	else
	{
		sprintf(buf, "Cannot update winner file.  Are you running the installed game,\n") ;
		cprintf(buf,39,41) ;
		sprintf(buf, "or a copy?  Delete local copy and run /usr/local/bin/domegame\nKEY:") ;
		cprintf(buf,39,41) ;
	}
#endif
	getchne() ;
	for (unsigned int i = 0 ; i < copyright.size() ; i++)
	{
		sprintf(buf,"%s\n", copyright[i].c_str()) ;
		//cprintf(buf, 30, 41) ;
		cprintf(buf, 39, 40) ;
		usleep(5000) ;
	}
} // main ends

/*
 This small script prints all available ANSI-colors on the terminal.
#!/bin/bash
for i in 30 31 32 33 34 35 36 37 39
do
 for j in 40 41 42 43 44 45 46 47 49
 do
   # skip if same fore- and backgroundcolor
#   if [ $j -eq $[ i + 10 ] ]; then
#     continue
#   fi
   echo -e $i $j "\033[${i};${j}mCOLOR\033[0m"
 done
done
*/
