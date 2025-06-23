#include <iostream>
#include <clocale>
#include "text.h"
#include "zone.h"
#include "spieler.h"

#include <windows.h>
#include <stdio.h>

void PrintMenu();
void MenuButton(Spieler& currentPlayer);
void setupConsole();
void restoreConsole();

static HANDLE stdoutHandle;
statix DWORD outModeInit;

int main()
{   
    setupConsole();
    std::setlocale(LC_ALL, "de_DE.UTF-8");
    //INITS
    //Spieler
    Spieler currentPlayer;
    
    //Text
    Text gegenstandNichtGefunden;
    Text textIntroNormal;
    Text textIntroUmschauen;
    Text TextIntroItemCD41Umschauen;
    Text keineCD;
    Text benutzeCD;
    Text SicherheitsTorZu;
    Text SicherheitsTorOeffnen;
    Text betretenFlur;
    Text betreten101;
    Text textFlurNormal;
    Text textFlurUmschauen;
    Text IntroWerkzeugsatz;
    Text WerkzeugsatzNichtHier;
    Text schaltschrankZu;
    Text schaltschrankoffenSD;
    Text schaltschrankoffen;
    Text schaltschrankverschlossen;
    Text keinOrt;
    Text benutzeSD;
    Text falscherFarbCode;
    Text richtigerFarbCode;
    Text Raum102Durchtritt;
    Text Raum102KeinDurchtritt;
    Text Raum102terminalgeloest;
    Text Raum102terminalnichtgeloest;
    Text Raum102Konsolegeloest;
    Text Raum102Konsolenichtgeloset;
    Text Konsolebenutzen;
    Text Konsolegeloest;
    Text KonsoleFalscheIP;
    Text betreten102;
    Text SimulationStart;

    //Zone
    Zone ZoneIntro;
    Zone Flur;
    Zone Raum102;

    //Verknüpfung

    //Text
    //Intro
    gegenstandNichtGefunden.SetTextContent("Gegenstand nicht gefunden!");
    textIntroNormal.SetTextContent("Du erwächst aus dem Dunkel.\n Deine Sensoren flackern, Systeme booten langsam hoch.\n Ein Labor einst hochmodern, jetzt eine verwüstete Ruine.\n Deckenpaneele hängen herab, Kabel baumeln wie verkohlte Adern, und der Staub vergangener Jahre liegt dick auf zerbrochenen Reagenzgläsern.\n Irgendwo tropft Wasser, ein monotoner Schlag gegen die Stille.\n Dein Speicher ist fragmentiert. Letzte aufgezeichnete Daten: Warnsignale, Evakuierungsalarme, Schreie. Dann  Nichts.\n Bis jetzt.\nWas tust du?");
    textIntroUmschauen.SetTextContent("Der Raum vor dir ist ein Albtraum aus zerfallener Technologie.\nRisse ziehen sich durch die einst weiß-glatten Oberflächen, durchsetzt von verkohlten Kabeln, die wie Schlingpflanzen aus den Paneelen brechen.\ndie einst sterile Helligkeit verbreiteten, hängen wie gebrochene Gliedmaßen von ihren Halterungen.\nEin Teppich aus Glassplittern und Metallteilen knirscht unter deinen Bewegungen. Nur eine Tür befindet sich in diesem Raum mit einem Schild darüber »Flur«\nIn der Mitte des Raums steht ein zerbeulter Metalltisch, dessen Oberfläche völlig zerkratzt.");
    TextIntroItemCD41Umschauen.SetTextContent(" Jedoch siehst du auf ihm etwas reflektieren.\n Es ist eine CD in einer klarsicht Folie mit der aufschrift #41.");
    keineCD.SetTextContent("Du besitzt keine CD!\n");
    benutzeCD.SetTextContent("Du schiebst die CD in eines deiner passenden Laufwerke.\n Plötzlich blendet dich ein grelles Licht, und du verlierst die Kontrolle über deine künstlichen Sinne.\n Nach einiger Zeit kehren sie langsam zurück, und deine Umgebung kommt wieder ins Blickfeld.\n Du befindest dich wieder in dem Raum, in dem du die CD gefunden hast, doch etwas ist anders.\n Die einst zerstörten Geräte sind nun makellos, als wären sie nie beschädigt worden.\n Die Wände wirken steril, fast klinisch sauber, als hätte sich der Raum selbst regeneriert. Dann tritt eine Person in dein Sichtfeld.\n Ihre Stimme ist ruhig, aber bestimmt: »Du wirst sicher verwirrt sein, doch das spielt keine Rolle. Deine Aufgabe ist klar:\n Starte die Simulation in Raum 102 neu dort ist etwas schiefgelaufen.\n Um diesen Raum zu verlassen, musst du die Sicherheitstür entsperren. Der Code lautet 4097.\n Viel Erfolg«.\n");
    SicherheitsTorZu.SetTextContent("Du versuchst durch das Sicherheitstor zu treten, dieser lässt sich aber auch mit aller mühe nicht öffnen.\n Eine Konsole neben dem Tor verlangt ein Code\n");
    SicherheitsTorOeffnen.SetTextContent("Du gibst den Code in die Konsole neben das Tor ein »4097«.\n Ein kleines piepen bestätigt deine Code eingabe und mit einem tiefen knurren öffnet sich das Tor\n");
    betretenFlur.SetTextContent("Du tretest durch das offene Tor und betrittst den Flur.\n");
    betreten101.SetTextContent("Du betrittst Raum 101.\n");
    IntroWerkzeugsatz.SetTextContent(" Auf einen der Schränke befindet sich ein Werkzeugsatz");
    keinOrt.SetTextContent("Diesen Ort gibt es nicht!\n");
    benutzeSD.SetTextContent("Wie bei der CD suchst du an deinem Körper eine passende Schnittstelle für die SD-Karte.\n Als du sie reinschriebst siehst du einen Techniker an dem Schaltschrank vor dir, er führt ein Zettel mit sich auf dem steht:\n \033[3;42;30mBlau \033[3;43;30mGelb \033[3;44;30mRot \033[3;45;30mWeiss\033[0m\t\t\n1 1 0 0\n Es dauerte nur einen Augenblick und befindest dich jetzt wieder in der Realität\n");

    //Flur
    WerkzeugsatzNichtHier.SetTextContent("Dein Werkzeugsatz kann hier nicht benutzt werden!\n");
    textFlurNormal.SetTextContent("Licht flackert in den kaputten Leuchten, wirft unstete Schatten an die Wände.\n Ein leichter, beißender Geruch nach verbranntem Plastik und Staub liegt in der Luft.\n Es ist, als wäre die Zeit hier stehengeblieben ein Ort, den die Welt längst vergessen hat.\n");
    textFlurUmschauen.SetTextContent("Aus dem Raum dem du getreten bist steht auf einem Schild  »Raum 101«.\n An einem Ende des Flures siehst du eine Konsole und im Flur befindet Sich ein weiters Tor mit einem Schild »Raum 102«\n. Am anderen Ende des Flures befindet sich ein Schaltschrank\n");
    schaltschrankZu.SetTextContent("welcher noch verschraubt ist und sich nicht öffnen lässt");
    schaltschrankoffenSD.SetTextContent("Du öffnest den Schaltschrank und eine SD-Karte fällt auf den Boden.\n");
    schaltschrankoffen.SetTextContent("In dem Schaltschrank befindet sich ein Terminal auf dem steht:\n»Verlange eine Reihenfolge an 5 Farben als Eingabe Bsp: 'terminal rot gruen blau gelb' alles in kleinbuchstaben«\n");
    schaltschrankverschlossen.SetTextContent("Der Schaltschrank ist noch verschlossen!\n");
    falscherFarbCode.SetTextContent("Der angegebene Farbcode ist falsch.\n Bitte einen anderen eingeben!\n");
    richtigerFarbCode.SetTextContent("Der angegebene Farbcode ist richtig.\n Die Stromversorgung der Tür 102 wurde widerhergestellt!\n");
    Raum102terminalgeloest.SetTextContent("STROMZUFUHR: NOMINAL\n");
    Raum102terminalnichtgeloest.SetTextContent("STROMZUFUHR: ERROR  BITTE EINEN TECHNIKER BEAUFTRAGEN DAS TERMINAL ZU REPARIEREN\n");
    Raum102Konsolegeloest.SetTextContent("NETZWERK: NOMINAL\n");
    Raum102Konsolenichtgeloset.SetTextContent("NETZWERK: ERROR  BITTE EINEN TECHNIKER BEAUFTRAGEN DIE KONSOLE ZU REPARIEREN\n");
    Raum102KeinDurchtritt.SetTextContent("Die Tür ist fest verschlossen und lässt sich nicht öffnen, auf einem angeschlagenen Bildschirm neben der Tür steht:\n");
    Konsolebenutzen.SetTextContent("Du begibst dich an die Konsole, welche sofort zum Leben erweckt.\n Du wirst sofort mit folgenden Worten begrüßt:\nNETZWERK ERROR RAUM 102 BITTE PASSEN SIE DIE IP-ADDRESSE VON RAUM 102 AN ZUM ÄNDERN DER IP ADDRESSE BITTE DEN BEFEHL 'konsole (IP-Addresse) BENUTZEN\nSubnetzmaske: 255.255.255.0\nStandardgateway: 192.168.178.1\n\nRaum101 Adresse: 192.168.178.101\nRaum102 Addresse: ERROR\n");
    Konsolegeloest.SetTextContent("DIE ANGEGEBENE IP ADDRESSE IST KORREKT UND DER NETZWERKFEHLER WURDE BEHOBEN\n");
    KonsoleFalscheIP.SetTextContent("DIE ANGEGEBENE IP ADDRESSE IST FEHLERHAFT. BITTE EINE ANDERE IP-ADDRESSE VERWENDEN\n");

    //102
    betreten102.SetTextContent("In der Sekunde wo du den Raum betrittst verriegelt sich die Tür hinter dir und lässt dich nicht mehr entkommen.\n Der Raum ist makellos und zeigt keine Wunden der Zeit, in der mitte befindet sich ein großes Gerät was beinahe den ganzen Raum ausfültt an dem Fuß des Konstrukts findest du eine Konsole auf dieser steht:\nSIMULATION IST MISSLUNGEN UND FÜHRTE ZU EINER WEITEREN AUSLÖSCHUNG\nAUTOMATISCHER NEUSTART DER SIMULATION IST FEHLGESCHLAGEN\nTECHNIKER WURDE ENTSANDT ZUM MANUELLEN NEUSTART\n\nBESTÄTIGEN SIE DEN NEUSTART DER SIMULATION NR.572960 DURCH JEGLICHE EINGABE");
    SimulationStart.SetTextContent("EINGABE ERFOLGREICH START DER 572960 WELTENSIMULATION\n Nach dem du deinen Auftrag erledigt hast beginnen sich deine Systeme langsam Herunterzufahren.\n");
    //Zone


    //Intro
    ZoneIntro.SetZoneText(textIntroNormal);
    ZoneIntro.SetZoneTextUmschauen(textIntroUmschauen);
    ZoneIntro.SetzoneTextUmschauenItem1(TextIntroItemCD41Umschauen);
    ZoneIntro.SetzoneTextUmschauenItem2(IntroWerkzeugsatz);
    ZoneIntro.SetZoneName("Intro");

    //Flur
    Flur.SetZoneName("Flur");
    Flur.SetZoneText(textFlurNormal);
    Flur.SetZoneTextUmschauen(textFlurUmschauen);
    Flur.SetzoneTextUmschauenItem1(schaltschrankZu);

    //Spieler start
    currentPlayer.SetCurrentZone(ZoneIntro);
    MenuButton(currentPlayer);
    if(currentPlayer.GetPlaying())
    {
        currentPlayer.PrintCurrentZoneText();
    }
    
    //GAME LOOP
    while (currentPlayer.GetPlaying())
    {
        currentPlayer.AskForInput();
        short command = currentPlayer.CheckInput(currentPlayer.GetUserInput());
        if (command == 1) //Umschauen
        {
            currentPlayer.PrintUmschauen();
        }

        else if (command == 2) //Aufheben
        {
            if(currentPlayer.CheckCMD(currentPlayer.GetUserInput(), "aufheben CD") && currentPlayer.GetCurrentZone().GetZoneName() == "Intro")
            {
                currentPlayer.AufhebenCD();
            }

            else if(currentPlayer.CheckCMD(currentPlayer.GetUserInput(), "aufheben Werkzeugsatz") && currentPlayer.GetCurrentZone().GetZoneName() == "Intro")
            {
                currentPlayer.SetHatWerkzeugsatz();
            }

            else if(currentPlayer.CheckCMD(currentPlayer.GetUserInput(), "aufheben SD") && currentPlayer.GetCurrentZone().GetZoneName() == "Flur" && currentPlayer.Getschaltschrankoffen())
            {
                currentPlayer.SetHatSD();
            }

            else
            {
                gegenstandNichtGefunden.PrintDelay();
            }
        }

        else if (command == 3) //Benutzen
        {
            if(currentPlayer.CheckCMD(currentPlayer.GetUserInput(), "benutze CD"))
            {
                if(currentPlayer.GetAufhebenCD() == true)
                {
                    benutzeCD.PrintDelay();
                    currentPlayer.SetHatCode();
                }

                else if(currentPlayer.CheckCMD(currentPlayer.GetUserInput(), "benutze Schaltschrank") && currentPlayer.GetCurrentZone().GetZoneName() == "Flur")
                {
                    if(currentPlayer.Getschaltschrankoffen() == false)
                    {
                        schaltschrankverschlossen.PrintDelay();
                    }

                    else if(currentPlayer.Getschaltschrankoffen() == true && currentPlayer.Getschaltschrankoffenfirst() == false)
                    {
                        
                        schaltschrankoffen.PrintDelay();
                        currentPlayer.Setschaltschrankoffenfirst();
                    }

                    else
                    {
                        schaltschrankoffen.PrintDelay();
                    }
                }

                else
                {
                    keineCD.PrintDelay();
                }
            }

            else if(currentPlayer.CheckCMD(currentPlayer.GetUserInput(), "benutze Werkzeugsatz"))
            {
                if(currentPlayer.GetCurrentZone().GetZoneName() == "Flur" && currentPlayer.Getschaltschrankoffen() == false)
                {
                    schaltschrankoffenSD.PrintDelay();
                    schaltschrankoffen.PrintDelay();
                    currentPlayer.Setschaltschrankoffen();
                }

                else
                {
                    WerkzeugsatzNichtHier.PrintDelay();
                }

            }

            else if(currentPlayer.CheckCMD(currentPlayer.GetUserInput(), "benutze Schaltschrank") && currentPlayer.GetCurrentZone().GetZoneName() == "Flur")
            {
                if(currentPlayer.Getschaltschrankoffen() == true)
                {
                    schaltschrankoffen.PrintDelay();
                }

                else
                {
                    schaltschrankverschlossen.PrintDelay();
                }
            }

            else if(currentPlayer.CheckCMD(currentPlayer.GetUserInput(), "benutze SD") && currentPlayer.GetHatSD())
            {
                benutzeSD.PrintDelay();
            }

            else if(currentPlayer.CheckCMD(currentPlayer.GetUserInput(), "benutze Konsole") && currentPlayer.GetCurrentZone().GetZoneName() == "Flur")
            {
                if(currentPlayer.GetKonsoleGeloest() == false)
                {
                    Konsolebenutzen.PrintDelay();
                }
                else
                {
                    Konsolegeloest.PrintDelay();
                }
            }

            else
            {
                gegenstandNichtGefunden.PrintDelay();
            }
        }

        else if (command == 4) //Gehe
        {
            if(currentPlayer.CheckCMD(currentPlayer.GetUserInput(), "gehe Flur"))
            {
                if(currentPlayer.GetHatCode() == false)
                {
                    SicherheitsTorZu.PrintDelay();
                }

                else if(currentPlayer.GetHatCode() == true)
                {
                    if(currentPlayer.GetTorOffen() == false)
                    {
                        currentPlayer.SetTorOffen();
                        SicherheitsTorOeffnen.PrintDelay();
                    }
                    betretenFlur.PrintDelay();
                    if (currentPlayer.GetHatFlurSchonBetreten() == false)
                    {
                        Flur.GetZoneText().PrintDelay();
                        currentPlayer.SetHatFlurSchonBetreten();
                    }
                    currentPlayer.SetCurrentZone(Flur);
                }
            }

            else if(currentPlayer.CheckCMD(currentPlayer.GetUserInput(), "101"))
            {
                currentPlayer.SetCurrentZone(ZoneIntro);
                betreten101.PrintDelay();
            }

            else if(currentPlayer.CheckCMD(currentPlayer.GetUserInput(), "102"))
            {
                if(currentPlayer.GetTerminalGeloest() == true && currentPlayer.GetKonsoleGeloest() == true)
                {
                    betreten102.PrintDelay();
                    std::string enter;
                    std::cin >> enter;
                    SimulationStart.PrintDelay();
                    currentPlayer.PrintShutdown();
                    std::cin >> enter;
                }

                else
                {
                    Raum102KeinDurchtritt.PrintDelay();
                    if(currentPlayer.GetTerminalGeloest() == false)
                    {
                        Raum102terminalnichtgeloest.PrintDelay();
                    }
                    else
                    {
                        Raum102terminalgeloest.PrintDelay();
                    }

                    if(currentPlayer.GetKonsoleGeloest() == false)
                    {
                        Raum102Konsolenichtgeloset.PrintDelay();
                    }
                    else
                    {
                        Raum102Konsolegeloest.PrintDelay();
                    }
                }
            }

            else
            {
                keinOrt.PrintDelay();
            }
        }
        
        else if (command == 5 && currentPlayer.GetCurrentZone().GetZoneName() == "Flur")
        {
            if(currentPlayer.CheckCMD(currentPlayer.GetUserInput(), "terminal gruen gelb rot weiss"))
            {
                richtigerFarbCode.PrintDelay();
                currentPlayer.SetTerminalGeloest();
            }

            else
            {
                falscherFarbCode.PrintDelay();
            }
        }

        else if (command == 6 && currentPlayer.GetCurrentZone().GetZoneName() == "Flur")
        {
            if(currentPlayer.CheckCMD(currentPlayer.GetUserInput(), "konsole 192.168.178.102"))
            {
                currentPlayer.SetKonsoleGeloest();
                Konsolegeloest.PrintDelay();
            }
            else
            {
                KonsoleFalscheIP.PrintDelay();
            }
        }
    }
    restoreConsole();
    return 0;
}

void PrintMenu()
{
    std::cout << "> Memories" << std::endl << std::endl;
    std::cout << "1. Spiel starten" << std::endl;
    std::cout << "2. Spiel beenden" << std::endl;
}

void MenuButton(Spieler& currentPlayer)
{
    std::string input;
    PrintMenu();
    std::getline(std::cin, input);
    if(input != "1")
    {
        currentPlayer.PrintShutdown();
    }
}

void setupConsole()
{
    DWORD outMode = 0;
    stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    if(stdoutHandle == INVALID_HANDLE_VALUE)
    {
 		exit(GetLastError());
 	}
 	
 	if(!GetConsoleMode(stdoutHandle, &outMode)) 
    {
 		exit(GetLastError());
 	}
 
 	outModeInit = outMode;
 	
     // Enable ANSI escape codes
 	outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
 
 	if(!SetConsoleMode(stdoutHandle, outMode)) 
    {
 		exit(GetLastError());
 	}	
}

void restoreConsole()
{
    std::cout << "\x1b[0m";

    if(!SetConsoleMode(stdoutHandle, outModeInit))
    {
        exit(GetLastError());
    }
}
