#include <iostream>
#include <windows.h>

using namespace std;

typedef enum {black,
              blue,
              green,
              cyan,
              red,
              magenta,
              yellow,
              white,
              gray,
              lightblue,
              lightgreen,
              lightcyan,
              lightred,
              lightmagenta,
              lightyellow,
              lightwhite} ;

void gotoxy (int x, int y)
{
    COORD coord; // coordinates of screen
    coord.X = x; coord.Y = y; // set value of x and y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // take cursor to that position
}
void setColor(int textColor, int bgColor) {
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + (bgColor * 16)));
   }


int Origin(int i,int j)
{
	setColor(cyan, black);

if(i==1 && j==1)
{cout<<"Most hydrogen is produced by heating natural gas with steam to form syngas (a mixture of hydrogen and carbon monoxide). The syngas is separated to give hydrogen.";
}
else if(i==1 && j==2)
{cout<<"No element at this position";
}
else if(i==1 && j==3)
{cout<<"No element at this position";
}
else if(i==1 && j==4)
{cout<<"No element at this position";
}
else if(i==1 && j==5)
{cout<<"No element at this position";
}
else if(i==1 && j==6)
{cout<<"No element at this position";
}
else if(i==1 && j==7)
{cout<<"No element at this position";
}
else if(i==1 && j==8)
{cout<<"No element at this position";
}
else if(i==1 && j==9)
{cout<<"No element at this position";
}
else if(i==1 && j==10)
{cout<<"No element at this position";
}
else if(i==1 && j==11)
{cout<<"No element at this position";
}
else if(i==1 && j==12)
{cout<<"No element at this position";
}
else if(i==1 && j==13)
{cout<<"No element at this position";
}
else if(i==1 && j==14)
{cout<<"No element at this position";
}
else if(i==1 && j==15)
{cout<<"No element at this position";
}
else if(i==1 && j==16)
{cout<<"No element at this position";
}
else if(i==1 && j==17)
{cout<<"No element at this position";
}
else if(i==1 && j==18)
{cout<<"Late 19th century: modern Latin, from Greek helios ‘sun’, because its existence was inferred from an emission line in the sun's spectrum.";
}

else if(i==2 && j==1)
{cout<<"Lithium was discovered from a mineral, while other common alkali metals were discovered from plant material.";
}
else if(i==2 && j==2)
{cout<<"Beryllium was discovered by Louis-Nicholas Vauquelin (FR) in 1798. The origin of the name comes from the Greek word beryllos meaning mineral beryl; also called glucinium from the Greek word glykys meaning sweet. It is a steel-grey metal resistant to attack by concentrated nitric acid.";
}
else if(i==2 && j==3)
{cout<<"No element at this position";
}
else if(i==2 && j==4)
{cout<<"No element at this position";
}
else if(i==2 && j==5)
{cout<<"No element at this position";
}
else if(i==2 && j==6)
{cout<<"No element at this position";
}
else if(i==2 && j==7)
{cout<<"No element at this position";
}
else if(i==2 && j==8)
{cout<<"No element at this position";
}
else if(i==2 && j==9)
{cout<<"No element at this position";
}
else if(i==2 && j==10)
{cout<<"No element at this position";
}
else if(i==2 && j==11)
{cout<<"No element at this position";
}
else if(i==2 && j==12)
{cout<<"No element at this position";
}
else if(i==2 && j==13)
{cout<<"Boron occurs as an orthoboric acid in some volcanic spring waters, and as borates in the minerals borax and colemanite. Extensive borax deposits are found in Turkey. However, by far the most important source of boron is rasorite. This is found in the Mojave Desert in California, USA.";
}
else if(i==2 && j==14)
{cout<<"It was first recognized as an element in the second half \nof the 18th century. Name: A.L. Lavoisier proposed carbon in 1789 from the Latin carbo meaning \ncharcoal. A.G. Werner and D.L.G. Harsten proposed graphite from the Greek grafo \nmeaning to write, referring to pencils, which were introduced in 1594.";
}
else if(i==2 && j==15)
{cout<<"Nitrogen was discovered by Daniel Rutherford (GB) in 1772.\n The origin of the name comes from the Greek words nitron genes meaning nitre and forming and \nthe Latin word nitrum (nitre is a common name for potassium nitrate, KNO3). ... \nNitrogen is obtained from liquid air by fractional distillation.";
}
else if(i==2 && j==16)
{cout<<"At least half of Earth's oxygen comes from the ocean. \nScientists estimate that 50-80% of the oxygen production on Earth comes from the ocean. The \nmajority of this production is from oceanic plankton — drifting plants, \nalgae, and some bacteria that can photosynthesize.";
}
else if(i==2 && j==17)
{cout<<"The name fluorine is derived from the mineral fluorite \nwhich comes from the Latin word fluere meaning to flow. The name was suggested by English \nchemist Sir Humphry Davy. Fluorine has one stable isotope, fluorine-19. It is the only \nform that fluorine occurs in naturally.";
}
else if(i==2 && j==18)
{cout<<"Neon is the fifth most abundant element in the universe. \nHowever, it is present in the Earth's atmosphere at a concentration of just 18 parts per million.";
}

if(i==3 && j==1)
{cout<<"Sodium is named for “soda”, the ancient name for \nsodium carbonate, and important industrial chemical for a long time. Sodium was isolated \nwhen studying soda and relatec compounds (today we have caustic soda/lye (sodium hydroxide), \nwashing soda (sodium carbonate), and baking soda \n(sodium bicarbonate) as three different industrially important sodas).";
}
else if(i==3 && j==2)
{cout<<"You may be getting the idea that elements tend \nto be named after minerals they are found in, like the mineral magnesia, which lent its name to \nmagnesium. Magnesia itself was named after a region of Thessaly";
}
else if(i==3 && j==3)
{cout<<"No element at this position";
}
else if(i==3 && j==4)
{cout<<"No element at this position";
}
else if(i==3 && j==5)
{cout<<"No element at this position";
}
else if(i==3 && j==6)
{cout<<"No element at this position";
}
else if(i==3 && j==7)
{cout<<"No element at this position";
}
else if(i==3 && j==8)
{cout<<"No element at this position";
}
else if(i==3 && j==9)
{cout<<"No element at this position";
}
else if(i==3 && j==10)
{cout<<"No element at this position";
}
else if(i==3 && j==11)
{cout<<"No element at this position";
}
else if(i==3 && j==12)
{cout<<"No element at this position";
}
else if(i==3 && j==13)
{cout<<"Similarly, the important mineral alum lent it’s name to aluminum";
}
else if(i==3 && j==14)
{cout<<"The very common mineral silica gave up its name to silicon.";
}
else if(i==3 && j==15)
{cout<<"One of the first indication of the discovery of phosphorous \nwas that it glowed with its own light, so it was named after the existing \nword for things which brought light — phosphoroux in French.";
}
else if(i==3 && j==16)
{cout<<"Sulfur/Sulphur comes ultimately from Latin, sulfur \nor the older sulphur, meaning the element (which occurs in \npure form near volcanos), and has a long association with fire.";
}
else if(i==3 && j==17)
{cout<<"Chlorine previously had such lovely names as \noxymuriatic acid gas or dephlogisticated marine gas. Eventually, someone noticed that \nthe gas had a light green color, and named it after the Greek word for green.";
}
else if(i==3 && j==18)
{cout<<"Argon doesn’t react with anything, \nso it can be understood why the name came from argon Latin for “lazy, non-working”.";
}

else if(i==4 && j==1)
{cout<<"From the English potash, which means pot-ash (potassium compound \nprepared from an alkali extracted in a 'pot' from the 'ash' of burnt wood or tree \nleaves). Potash is literal translation of the Dutch potaschen, which means pot ashes";
}
else if(i==4 && j==2)
{cout<<"From Latin calx, which means lime. Calcium was \nknown as early as the first century when the Ancient Romans prepared lime as calcium oxide. ";
}
else if(i==4 && j==3)
{cout<<"Named from Latin Scandia, Scandinavia. ";
}
else if(i==4 && j==4)
{cout<<"For the Titans, the first sons of Gaia in Greek mythology.";
}
else if(i==4 && j==5)
{cout<<"From Old Norse Vanadís, one of the names of the Vanr \ngoddess Freyja in Norse  mythology, because of multicoloured chemical compounds deemed beautiful.";
}
else if(i==4 && j==6)
{cout<<"From Greek ???µa (chróma), colour, because of its multicoloured compounds. This word was adapted as the French chrome, and adding the suffix -ium created the English chromium";
}
else if(i==4 && j==7)
{cout<<"From Latin Magnesia, ultimately from Ancient Greek \nregion Magnesia. The word Magnesia evolved into manganese in Italian and into manganèse in French. ";
}
else if(i==4 && j==8)
{cout<<"From the Anglo-Saxon isern which is derived from Proto-Germanic isarnan meaning holy metal or strong metal. ";
}
else if(i==4 && j==9)
{cout<<"From German Kobold, which means goblin. The metal was named \nby miners, becauseit was poisonous and troublesome (polluted and degraded by other \nmined elements, suchas nickel). Other sources cite the origin in the silver miners' belief that\n cobalt had beenplaced by Kobolds, who had stolen the silver. Some suggest that the name \nmay have been derived fromGreek ??ßa??? (kobalos), which means mine and which may have common \nroots with kobold, goblin, and cobalt. ";
}
else if(i==4 && j==10)
{cout<<"From the Swedish kopparnickel, meaning copper-coloured ore. This referred to theore niccolite from which it was obtained.";
}
else if(i==4 && j==11)
{cout<<"Possibly derived from Greek ??p???? (Kyprios) (which comes from ??p??? (Kypros),the Greek name of Cyprus) via Latin cuprum, West Germanic *kupar, \nOld English copercopor, and Middle English coper. The Latin term, during the Roman Empire, was \naescyprium aes was the generic term for copper alloys such as bronze. Cyprium means Cyprus \nor which is from Cyprus, where so much of it was mined; it was simplified to cuprum and \nthen eventually Anglicized as  copper (Old English coper/copor).";
}
else if(i==4 && j==12)
{cout<<"From German Zink which is related to Zinken prong, point, \nprobably alluding to its spiky crystals. May be derived from Old Persian. ";
}
else if(i==4 && j==13)
{cout<<"From Latin Gallia, which means Gaul (Ancient France), and also \ngallus, which means rooster. The element was obtained as free metal by Lecoq de Boisbaudran, \nwho named it after his native land France. Allegations were later made that he had also named \nit for himself, as gallus is Latin for le coq (rooster), but he denied that this had been \nhis intention.";
}
else if(i==4 && j==14)
{cout<<"From Latin Germania, which means Germany. Former name eka-silicon by Mendeleev.";
}
else if(i==4 && j==15)
{cout<<"From Greek ??se????? (arsenikon), which is adapted from \nSyriac ?????? ??????? ((al) zarniqa)[29] and Persian ????? (zarnik), yellow orpiment. The Greek \narsenikon is paretymologically related to the Greek word ??se????? (arsenikos), which means \nmasculine or  potent. These words were adapted as the Latin arsenicum and Old French arsenic, \nwhich is the source for the English arsenic.";
}
else if(i==4 && j==16)
{cout<<"From Greek se???? (selene), which means Moon, and also moon-goddess Selene";
}
else if(i==4 && j==17)
{cout<<"ß??µ?? (brómos) means stench (literally: clangor), due to its characteristic smell. ";
}
else if(i==4 && j==18)
{cout<<"From Greek ???pt?? (kryptos), which means hidden one, \nbecause of its colourless, odorless, tasteless, gaseous properties, as well as its rarity in nature. ";
}

if(i==5 && j==1)
{cout<<"Rubidium was discovered in 1861 by Robert Bunsen and Gustav Kirchhoff, in Heidelberg, Germany, in the mineral lepidolite through flame spectroscopy. Because of the bright red lines in its emission spectrum, they chose a name derived from the Latin word rubidus, meaning deep red.";
}
else if(i==5 && j==2)
{cout<<"The Scottish village was called Strontian, the mineral found there, strontianite and the new element strontium.";
}
else if(i==5 && j==3)
{cout<<"The element is named after ytterbite, a mineral first identified in 1787 by the chemist Arrhenius. He named the mineral after the village of Ytterby, in Sweden, where it had been discovered.";
}
else if(i==5 && j==4)
{cout<<"Totally pure zirconium was only produced in 1925 by the Dutch chemists Anton Eduard van Arkel and Jan Hendrik de Boer by the decomposition of zirconium tetraiodide (ZrI4).";
}
else if(i==5 && j==5)
{cout<<"Niobium was discovered in 1801 by Charles Hatchett in an ore called columbite sent to England in the 1750s by John Winthrop the Younger, the first goveror of Connecticut, USA. Hatchett called the new element columbium. ... The name niobium is now used in place of the original name columbium.";
}
else if(i==5 && j==6)
{cout<<"Molybdenum is a chemical element with the symbol Mo and atomic number 42. The name is from Neo-Latin molybdaenum, which is based on Ancient Greek ????ßd?? molybdos, meaning lead, since its ores were confused with lead ores.";
}
else if(i==5 && j==7)
{cout<<"Technetium was discovered by Emilio Segrè in 1937 in Italy. He investigated molybdenum from California which had been exposed to high energy radiation and he found technetium to be present and separated it. Today, this element is extracted from spent nuclear fuel rods in tonne quantities.";
}
else if(i==5 && j==8)
{cout<<"D.s on the chemistry of the metals of the so-called platinum group of which ruthenium is one.";
}
else if(i==5 && j==9)
{cout<<"Rhodium was discovered in 1803 by William Wollaston.";
}
else if(i==5 && j==10)
{cout<<"Palladium is named after the asteroid Pallas, in turn named after the Greek goddess of wisdom, Pallas.";
}
else if(i==5 && j==11)
{cout<<"Our name for the element is derived from the Anglo-Saxon for silver, 'seolfor,' which itself comes from ancient Germanic 'silabar. ' Silver's chemical symbol, Ag, is an abbreviation of the Latin word for silver, 'argentum. ' The Latin word originates from argunas, a Sanskrit word meaning shining.";
}
else if(i==5 && j==12)
{cout<<"The only mineral containing significant quantities of cadmium is greenockite (cadmium sulfide). It is also present in small amounts in sphalerite.";
}
else if(i==5 && j==13)
{cout<<"Indium was discovered in 1863 by Ferdinand Reich at the Freiberg School of Mines in Germany. ... However, because he was colour-blind he asked Hieronymous Richter to look at the spectrum, and he noted a brilliant violet line, and this eventually gave rise to the name indium, from the Latin word indicum meaning violet.";
}
else if(i==5 && j==14)
{cout<<"Alloys of tin are important, such as soft solder, pewter, bronze and phosphor bronze. The name comes from the Anglo-Saxon 'tin'";
}
else if(i==5 && j==15)
{cout<<"Word origin: Antimony was named after the Greek words anti and monos to mean “a metal not found alone.” The chemical symbol, Sb, comes from the element's historical name, stibium.";
}
else if(i==5 && j==16)
{cout<<"Tellurium was discovered in 1783 by Franz Joseph Müller von Reichenstein at Sibiu, Romania.";
}
else if(i==5 && j==17)
{cout<<"Iodine - Element information, properties and uses | Periodic Table. The name is derived from the Greek 'iodes' meaning violet.";
}
else if(i==5 && j==18)
{cout<<"Xenon was discovered in July 1898 by William Ramsay and Morris Travers at University College London.";
}

if(i==6 && j==1)
{cout<<"Origin of the name The name comes from the Latin 'caesius', meaning sky blue, and derived from its flame colour.";
}
else if(i==6 && j==2)
{cout<<"\n\nThis was the mineral barite (barium sulfate, BaSO4). When Bologna stone, as it became known, was investigated by Carl Scheele in 1760s he realised it was the sulfate of an unknown element.";
}
else if(i==6 && j==3)
{cout<<"\n\nNo element at this position";
}
else if(i==6 && j==4)
{cout<<"\n\nThe element is number 72 in the periodic table, and is called hafnium. Discovery date 1923 Origin of the name: The name is derived from the Latin name for Copenhagen, 'Hafnia'";
}
else if(i==6 && j==5)
{cout<<"Tantalum now sits below niobium in the periodic table. It has an atomic number of 73, and an atomic weight of just under 181.";
}
else if(i==6 && j==6)
{cout<<"They make the point that students will have to learn some history of chemistry to know why the element symbol is W.";
}
else if(i==6 && j==7)
{cout<<"Tungsten is the only metallic element with a higher melting point. Rhenium is used as an additive to tungsten- and molybdenum-based alloys to give useful properties.";
}
else if(i==6 && j==8)
{cout<<"A shiny, silver metal that resists corrosion. It is the densest of all the elements and is twice as dense as lead.";
}
else if(i==6 && j==9)
{cout<<"Iridium, with atomic number 77 and two stable isotopes, 191 and 193, turns up in an alloy with platinum in the standard bar and weight used for many years to define the metre and the kilogramme.";
}
else if(i==6 && j==10)
{cout<<"Platinum has the symbol Pt, its atomic number is 78, and its atomic weight is 195.09. The name is derived from the Spanish platina, meaning silver. Platinum was discovered in South America independently by Antonio de Ulloa in 1735 and by N. Wood in 1741, but it had been in use by pre-Columbian Indians.";
}
else if(i==6 && j==11)
{cout<<"Gold is element 79 and its symbol is Au. Though the name is Anglo Saxon, gold originated from the Latin Aurum, or shining dawn, and previously from the Greek.";
}
else if(i==6 && j==12)
{cout<<"The name mercury originated in 6th-century alchemy, in which the symbol of the planet was used to represent the metal; the chemical symbol Hg derives from the Latin hydrargyrum, “liquid silver.” Although its toxicity was recognized at an early date, its main application was for medical purposes.";
}
else if(i==6 && j==13)
{cout<<"Discovery date 1861 Origin of the name. Thallium is derived from the Greek 'thallos', meaning a green twig.";
}
else if(i==6 && j==14)
{cout<<"Origin of name : from the Anglo-Saxon word lead; Latin, plumbum (the origin of the symbol Pb is the Latin word plumbum meaning liquid silver.";
}
else if(i==6 && j==15)
{cout<<"Bismuth occurs as the native metal, and in ores such as bismuthinite and bismite.";
}
else if(i==6 && j==16)
{cout<<"Polonium, (element 84), was discovered in 1898 and named after Poland, the homeland of Marie Curie (Ne Sklodowska) who found it with her husband Pierre Curie.";
}
else if(i==6 && j==17)
{cout<<"Astatine was first produced in 1940 by Dale R. Coson, Kenneth Ross Mackenzie and Emilio Segrè at the University of California, Berkeley. ... The scientists found that the isotope they created was radioactive, so they named the element using the Greek 'astatos' meaning unstable.";
}
else if(i==6 && j==18)
{cout<<"Radon is a colourless and odourless gas. It is chemically inert, but radioactive.";
}

if(i==7 && j==1)
{cout<<"\n\nFrancium, number 87, was the last of these elements to be discovered in nature.Discovery date 1939. Discovered by Marguerite Perey. Origin of the name Francium is named after France";
}
else if(i==7 && j==2)
{cout<<"\n\nThe metal itself was isolated by Marie Curie and André Debierne in 1911, by means of the electrolysis of radium chloride";
}
else if(i==7 && j==3)
{cout<<"\n\nNo element at this position";
}
else if(i==7 && j==4)
{cout<<"\n\nIn 1964, Russian scientists from a lab in Dubna were the first to synthesise the element. ... The American team challenged the Russians' discovery claim and named element 104 rutherfordium (Rf) in honour of Ernest Rutherford, often called the father of nuclear physics.";
}
else if(i==7 && j==5)
{cout<<"Eventually, the International Union of Pure and Applied Chemistry (IUPAC) decided it should be called dubnium.";
}
else if(i==7 && j==6)
{cout<<"Seaborgium is a synthetic chemical element with the symbol Sg and atomic number 106. It is named after the American nuclear chemist Glenn T. Seaborg. As a synthetic element, it can be created in a laboratory but is not found in nature.";
}
else if(i==7 && j==7)
{cout<<"This podcast is about one of these elements, number 107 in the periodic table, called bohrium.";
}
else if(i==7 && j==8)
{cout<<"Hassium is a chemical element with the symbol Hs and the atomic number 108.  Naming: after Hassia, Latin for Hesse, Germany, where it was discovered  Discovery: Gesellschaft für Schwerionenforschung (1984)";
}
else if(i==7 && j==9)
{cout<<"Meitnerium is a synthetic chemical element with the symbol Mt and atomic number 109. ... The GSI Helmholtz Centre for Heavy Ion Research near Darmstadt, Germany, first created this element in 1982. It is named after Lise Meitner.";
}
else if(i==7 && j==10)
{cout<<"A man-made element of which only a few atoms have ever been created. It that is formed by fusing nickel and lead atoms in a heavy ion accelerator.";
}
else if(i==7 && j==11)
{cout<<"Roentgenium (Rg), artificially produced transuranium element of atomic number 111. ... Element 111 was named roentgenium after the German physicist Wilhelm Röntgen, the discoverer of X-rays. The longest-lasting isotope, roentgenium-280, has a half-life of 3.6 seconds and decays to meitnerium-276.";
}
else if(i==7 && j==12)
{cout<<"Copernicium (Cn), artificially produced transuranium element of atomic number 112. ... The discoverers named it copernicium, after Polish astronomer Nicolaus Copernicus, in July 2009, and IUPAC approved that name in February 2010.";
}
else if(i==7 && j==13)
{cout<<"On November 28th, 2016 element 113 was named “nihonium” with the symbol Nh. The name was proposed by the discoverers at RIKEN Nishina Center for Accelerator-Based Science in Japan. The name means mean “the Land of Rising Sun” and comes from the word “Nihon,” which means “Japan” in Japanese.";
}
else if(i==7 && j==14)
{cout<<"Word origin: Flerovium is named for Russian physicist Georgy Flyorov, founder of the Joint Institute of Nuclear Research in Dubna, Russia, where the element was discovered. Discovery: Flerovium was first produced in 1998 and announced in 1999 by Joint Institute of Nuclear Research scientists.";
}
else if(i==7 && j==15)
{cout<<"Moscovium is a synthetic chemical element with the symbol Mc and atomic number 115. It was first synthesized in 2003 by a joint team of Russian and American scientists at the Joint Institute for Nuclear Research (JINR) in Dubna, Russia.";
}
else if(i==7 && j==16)
{cout<<"The element is named after the Lawrence Livermore National Laboratory in the United States, which collaborated with the Joint Institute for Nuclear Research (JINR) in Dubna, Russia to discover livermorium during experiments made between 2000 and 2006.";
}
else if(i==7 && j==17)
{cout<<"The discoverers named it tennessine after the state of Tennessee, where centres of research into transuranium elements (such as Oak Ridge National Laboratory, the University of Tennessee at Knoxville, and Vanderbilt University) are located. The name tennessine was approved by IUPAC in November 2016.";
}
else if(i==7 && j==18)
{cout<<"Oganesson is a synthetic chemical element with the symbol Og and atomic number 118. It was first synthesized in 2002 at the Joint Institute for Nuclear Research (JINR) in Dubna, near Moscow, Russia, by a joint team of Russian and American scientists.";
}

if(i==8 && j==1)
{cout<<"\n\nMost hydrogen is produced by heating natural gas with steam to \nform syngas (a mixture of hydrogen and carbon monoxide). The syngas is separated to give hydrogen.";
}
else if(i==8 && j==2)
{cout<<"\n\nNo element at this position";
}
else if(i==8 && j==3)
{cout<<"\n\nNo element at this position";
}
else if(i==8 && j==4)
{cout<<"\n\nLanthanum was first found by the Swedish chemist Carl Gustaf Mosander in 1839 as an impurity in cerium nitrate – hence the name lanthanum, from the Ancient Greek ?a????e?? (lanthanein), meaning to lie hidden.";
}
else if(i==8 && j==5)
{cout<<"Cerium as the oxide (ceria) was discovered in 1803 by Swedish chemists Jöns Jacob Berzelius and Wilhelm Hisinger, working together, and independently by German chemist Martin Klaproth. It was named after the asteroid Ceres, which was discovered in 1801. Cerium occurs in bastnasite, monazite, and many other minerals.";
}
else if(i==8 && j==6)
{cout<<"In 1885, the Austrian chemist Baron Carl Auer von Welsbach separated didymium into two elements that gave salts of different colours, which he named praseodymium and neodymium. The name praseodymium comes from the Greek prasinos, meaning green, and didymos (d?d?µ??), twin.";
}
else if(i==8 && j==7)
{cout<<"Neodymium - Element information, properties and uses | Periodic Table. The name is derived from the Greek 'neos didymos' meaning new twin.";
}
else if(i==8 && j==8)
{cout<<"Promethium is a chemical element with the symbol Pm and atomic number 61. Discovery: Charles D. Coryell, Jacob A. Marinsky, Lawrence E. Glendenin (1945).  Named by Grace Mary Coryell (1945)";
}
else if(i==8 && j==9)
{cout<<"The mineral samarskite, from which samarium was first isolated, is named after Colonel Samarsky, a Russian mine official.";
}
else if(i==8 && j==10)
{cout<<"Europium is a lanthanide, one of those unfamiliar elements sitting outside the main structure of the periodic table. With atomic number 63, it inhabits the bar of elements that squeeze numerically between barium and hafnium.";
}
else if(i==8 && j==11)
{cout<<"In 1880, Marignac extracted yet another new rare earth from didymium, as did Paul-Émile Lecoq de Boisbaudran in 1886, and it was the latter who called it gadolinium.";
}
else if(i==8 && j==12)
{cout<<"Terbium was first isolated in 1843 by the Swedish chemist Carl Mosander at Stockholm. He had already investigated cerium oxide and separated a new element from it, lanthanum, and now he focussed his attention on yttrium, discovered in 1794, because he thought this too might harbour another element.";
}
else if(i==8 && j==13)
{cout<<"Dysprosium was first identified in 1886 by Paul Émile Lecoq de Boisbaudran, but it was not isolated in pure form until the development of ion-exchange techniques in the 1950s.";
}
else if(i==8 && j==14)
{cout<<"Its oxide was first isolated from rare-earth ores by Cleve in 1878. The element's name comes from Holmia, the Latin name for the city of Stockholm.";
}
else if(i==8 && j==15)
{cout<<"In 1843, at Stockholm, Carl Mosander obtained two new metal oxides from yttrium, which had been know since 1794. One of these was erbium oxide, which was pink. (The other was terbium oxide, which was yellow.)";
}
else if(i==8 && j==16)
{cout<<"Thulium was first isolated in 1879 as its oxide by Per Teodor Cleve at the University of Uppsala, Sweden.";
}
else if(i==8 && j==17)
{cout<<"In common with many lanthanide elements, ytterbium is found principally in the mineral monazite. It can be extracted by ion exchange and solvent extraction.";
}
else if(i==8 && j==18)
{cout<<"Lutetium was discovered in 1907–08 by Austrian chemist Carl Auer von Welsbach and Georges Urbain, working independently. Urbain derived the name for the element from Lutetia, the ancient Roman name for Paris, to honour his native city.";
}

if(i==9 && j==1)
{cout<<"\n\nNo element at this position";
}
else if(i==9 && j==2)
{cout<<"\n\nNo element at this position";
}
else if(i==9 && j==3)
{cout<<"\n\nNo element at this position";
}
else if(i==9 && j==4)
{cout<<"\n\nActinium is a chemical element with the symbol Ac and atomic number 89. Discovery and first isolation. Friedrich Oskar Giesel (1902, 1903). Named by André-Louis Debierne (1899)";
}
else if(i==9 && j==5)
{cout<<"Thorium is found as the minerals thorite, uranothorite and thorianite. It is also found in monazite, which is the most important commercial source.";
}
else if(i==9 && j==6)
{cout<<"Protactinium (formerly protoactinium) is a chemical element with the symbol Pa and atomic number 91.";
}
else if(i==9 && j==7)
{cout<<"The 1789 discovery of uranium in the mineral pitchblende is credited to Martin Heinrich Klaproth, who named the new element after the recently discovered planet Uranus. Eugène-Melchior Péligot was the first person to isolate the metal and its radioactive properties were discovered in 1896 by Henri Becquerel.";
}
else if(i==9 && j==8)
{cout<<"Neptunium was first made in 1940 by Edwin McMillan and Philip Abelson at Berkeley, California. It came from a uranium target that had been bombarded with slow neutrons and which then emitted unusual beta-rays indicating a new isotope.";
}
else if(i==9 && j==9)
{cout<<"Plutonium was first made in December 1940 at Berkeley, California, by Glenn Seaborg, Arthur Wahl, Joseph Kennedy, and Edwin McMillan.";
}
else if(i==9 && j==10)
{cout<<"Americium is a synthetic radioactive chemical element with the symbol Am and atomic number 95.";
}
else if(i==9 && j==11)
{cout<<"Curium was first made by the team of Glenn Seaborg, Ralph James, and Albert Ghiorso in 1944, using the cyclotron at Berkeley, California.";
}
else if(i==9 && j==12)
{cout<<"berkelium (Bk), synthetic chemical element of the actinoid series of the periodic table, atomic number 97. Not occurring in nature, berkelium (as the isotope berkelium-243) was discovered in December 1949 by American chemists Stanley G. ... The element was named after the city of Berkeley, where it was discovered.";
}
else if(i==9 && j==13)
{cout<<"Californium is a radioactive chemical element with the symbol Cf and atomic number 98. The element was first synthesized in 1950 at the Lawrence Berkeley National Laboratory (then the University of California Radiation Laboratory), by bombarding curium with alpha particles (helium-4 ions).";
}
else if(i==9 && j==14)
{cout<<"Einsteinium was discovered in the debris of the first thermonuclear explosion which took place on a Pacific atoll, on 1 November 1952.";
}
else if(i==9 && j==15)
{cout<<"Fermium was discovered in 1953 in the debris of the first thermonuclear explosion which took place on a Pacific atoll on 1 November 1952.";
}
else if(i==9 && j==16)
{cout<<"Seventeen atoms of mendelevium were made in 1955 by Albert Ghiorso, Bernard Harvey, Gregory Chopin, Stanley Thompson, and Glenn Seaborg.";
}
else if(i==9 && j==17)
{cout<<"Word Origin: Nobelium is named after Alfred Nobel, the inventor of dynamite. ... The Berkeley team produced an isotope,254 No, with a half-life of three seconds, and the Russians replicated that discovery. Credit for nobelium's discovery was given to the Berkeley team, who decided to keep the name nobelium.";
}
else if(i==9 && j==18)
{cout<<"Lawrencium is a synthetic chemical element with the symbol Lr (formerly Lw) and atomic number 103. It is named in honor of Ernest Lawrence, inventor of the cyclotron, a device that was used to discover many artificial radioactive elements.";
}




return 0;
}


int physical(int i, int j)
{
setColor(cyan, black);
if(i==1 && j==1)
{cout<<"At standard temperature and pressure, hydrogen is a nontoxic, nonmetallic, odorless, tasteless, colorless, and highly combustible diatomic gas with the molecular formula H2. Hydrogen is also prevalent on Earth in the form of chemical compounds such as hydrocarbons and water.";
}
else if(i==1 && j==2)
{cout<<"No element at this position";
}
else if(i==1 && j==3)
{cout<<"No element at this position";
}
else if(i==1 && j==4)
{cout<<"No element at this position";
}
else if(i==1 && j==5)
{cout<<"No element at this position";
}
else if(i==1 && j==6)
{cout<<"No element at this position";
}
else if(i==1 && j==7)
{cout<<"No element at this position";
}
else if(i==1 && j==8)
{cout<<"No element at this position";
}
else if(i==1 && j==9)
{cout<<"No element at this position";
}
else if(i==1 && j==10)
{cout<<"No element at this position";
}
else if(i==1 && j==11)
{cout<<"No element at this position";
}
else if(i==1 && j==12)
{cout<<"No element at this position";
}
else if(i==1 && j==13)
{cout<<"No element at this position";
}
else if(i==1 && j==14)
{cout<<"No element at this position";
}
else if(i==1 && j==15)
{cout<<"No element at this position";
}
else if(i==1 && j==16)
{cout<<"No element at this position";
}
else if(i==1 && j==17)
{cout<<"No element at this position";
}
else if(i==1 && j==18)
{cout<<"Helium is a colourless, odourless, insipid and non-toxic gas. It's less soluble in water than any other gas.";
}


if(i==2 && j==1)
{cout<<"\n\nLithium has a melting point of 180.54 C, a boiling point of 1342 C, a specific gravity of 0.534 (20 C), and a valence of 1. It is the lightest of the metals, with a density approximately half that of water. Under ordinary conditions, lithium is the least dense of the solid elements.";
}
else if(i==2 && j==2)
{cout<<"\n\nBeryllium is a steel gray and hard metal that is brittle at room temperature and has a close-packed hexagonal crystal structure. It has exceptional stiffness (Young's modulus 287 GPa) and a melting point of 1287 °C.";
}
else if(i==2 && j==3)
{cout<<"\n\nNo element at this position";
}
else if(i==2 && j==4)
{cout<<"\n\nNo element at this position";
}
else if(i==2 && j==5)
{cout<<"No element at this position";
}
else if(i==2 && j==6)
{cout<<"No element at this position";
}
else if(i==2 && j==7)
{cout<<"No element at this position";
}
else if(i==2 && j==8)
{cout<<"No element at this position";
}
else if(i==2 && j==9)
{cout<<"No element at this position";
}
else if(i==2 && j==10)
{cout<<"No element at this position";
}
else if(i==2 && j==11)
{cout<<"No element at this position";
}
else if(i==2 && j==12)
{cout<<"No element at this position";
}
else if(i==2 && j==13)
{cout<<"At standard temperatures boron is a poor electrical conductor but is a good conductor at high temperatures.";
}
else if(i==2 && j==14)
{cout<<"CARBON: boiling point 4,827 °C (8,721 °F). density: diamond 3.52 g/cm3. graphite 2.25 g/cm3";
}
else if(i==2 && j==15)
{cout<<"Nitrogen gas (chemical symbol N) is generally inert, nonmetallic, colorless, odorless and tasteless. Its atomic number is 7, and it has an atomic weight of 14.0067. Nitrogen has a density of 1.251 grams/liter at 0 C and a specific gravity of 0.96737, making it slightly lighter than air.";
}
else if(i==2 && j==16)
{cout<<"In normal conditions oxygen is a colourless, odourless and insipid gas; it condensates in a light blue liquid. Oxygen is part of a small group of gasses literally paramagnetic, and it’s the most paramagnetic of all. Liquid oxygen is also slightly paramagnetic.";
}
else if(i==2 && j==17)
{cout<<"Fluorine (F), most reactive chemical element and the lightest member of the halogen elements, or Group 17 (Group VIIa) of the periodic table.";
}
else if(i==2 && j==18)
{cout<<"It is a colorless, tasteless odorless inert gas. It changes to reddish-orange color in vacuum tube. It is chemically inactive. It has the lowest liquid range of any element.";
}

if(i==3 && j==1)
{cout<<"Symbol: Na.Melting point: 97.794°C.Boiling point: 882.940°C.Density (g cm-3): 0.97.Atomic mass: 22.990.Atomic number: 11..";
}
else if(i==3 && j==2)
{cout<<"Magnesium oxide nanoparticles are odorless and non-toxic. They possess high hardness, high purity and a high melting point.";
}
else if(i==3 && j==3)
{cout<<"\n\nNo element at this position";
}
else if(i==3 && j==4)
{cout<<"\n\nNo element at this position";
}
else if(i==3 && j==5)
{cout<<"No element at this position";
}
else if(i==3 && j==6)
{cout<<"No element at this position";
}
else if(i==3 && j==7)
{cout<<"No element at this position";
}
else if(i==3 && j==8)
{cout<<"No element at this position";
}
else if(i==3 && j==9)
{cout<<"No element at this position";
}
else if(i==3 && j==10)
{cout<<"No element at this position";
}
else if(i==3 && j==11)
{cout<<"No element at this position";
}
else if(i==3 && j==12)
{cout<<"No element at this position";
}
else if(i==3 && j==13)
{cout<<"Solid, nonmagnetic, non-lustrous, silvery-white with slight bluish tint. High ductility. Aluminum can be beaten very thin.";
}
else if(i==3 && j==14)
{cout<<"The atomic number of silicon is 14 and its relative atomic mass is 28.085 u. The density of silicon is 2.3296 gram per cubic centimeter. The silicon melting point is 1,410°C and the silicon boiling point is 3,265°C. Silicon in its purest form is an intrinsic semiconductor.";
}
else if(i==3 && j==15)
{cout<<"The melting point of phosphorus (white) is 44.1°C, boiling point (white) is 280°C, specific gravity (white) is 1.82, (red) 2.20, (black) 2.25-2.69, with a valence of 3 or 5. There are four allotropic forms of phosphorus: two forms of white (or yellow), red, and black (or violet).";
}
else if(i==3 && j==16)
{cout<<"Pure sulfur is a tasteless, odourless, brittle solid that is pale yellow in colour, a poor conductor of electricity, and insoluble in water. It reacts with all metals except gold and platinum, forming sulfides; it also forms compounds with several nonmetallic elements.";
}
else if(i==3 && j==17)
{cout<<"Chlorine has a melting point of -100.98°C, boiling point of -34.6°C, density of 3.214 g/l, specific gravity of 1.56 (-33.6°C), with a valence of 1, 3, 5, or 7. Chlorine is a member of the halogen group of elements and directly combines with almost all of the other elements";
}
else if(i==3 && j==18)
{cout<<"Argon is colorless, odorless, nonflammable and nontoxic as a solid, liquid or gas. Argon is chemically inert under most conditions and forms no confirmed stable compounds at room temperature.";
}

if(i==4 && j==1)
{cout<<"Potassium is a soft, silvery-white metal with a melting point of 63°C (145°F) and a boiling point of 770°C (1,420°F). Its density is 0.862 grams per cubic centimeter, less than that of water (1.00 grams per cubic centimeter). That means that potassium metal can float on water.";
}
else if(i==4 && j==2)
{cout<<"Calcium is a fairly soft metal with a shiny silver surface when first cut. The surface quickly becomes dull as calcium reacts with oxygen to form a coating of white or gray calcium oxide. Calcium's melting point is 850°C (1,560°F) and its boiling point is 1,440°C (2,620°F).";
}
else if(i==4 && j==3)
{cout<<"Scandium metal is a silvery-white solid with a slight pink or yellow tint when exposed to air. It has a melting point of 1,538°C (2,800°F) and a boiling point of about 2,700°C (4,900°F). Its density is 2.99 grams per cubic centimeter.";
}
else if(i==4 && j==4)
{cout<<"Titanium has a melting point of 1660 +/- 10°C, boiling point of 3287°C, specific gravity of 4.54, with a valence of 2, 3, or 4. Pure titanium is a lustrous white metal with low density, high strength, and high corrosion resistance.";
}
else if(i==4 && j==5)
{cout<<"Vanadium is a silvery-white, ductile, metallic-looking solid. Ductile means capable of being drawn into thin wires. Its melting point is about 1,900°C (3,500°F) and its boiling point is about 3,000°C (5,400°F). Its density is 6.11 grams per cubic centimeter.";
}
else if(i==4 && j==6)
{cout<<"Chromium has a melting point of 1857+/-20°C, a boiling point of 2672°C, a specific gravity of 7.18 to 7.20 (20°C), with valences usually 2, 3, or 6. The metal is a lustrous steel-gray color which takes a high polish. It is hard and resistant to corrosion";
}
else if(i==4 && j==7)
{cout<<"Physical state Solid Solid \nMelting point 1,244 °Cc 650 °C\nBoiling point 2,095 °Cb 1,412 °Cb";
}
else if(i==4 && j==8)
{cout<<"Iron is a chemical element with symbol Fe and atomic number 26. Classified as a transition metal, Iron is a solid at room temperature.";
}
else if(i==4 && j==9)
{cout<<"Cobalt is a hard ferromagnetic, silver-white, hard, lustrous, brittle element. It is a member of group VIII of the periodic table. Like iron, it can be magnetized. It is similar to iron and nickel in its physical properties";
}
else if(i==4 && j==10)
{cout<<"Nickel is a hard silver white metal, which forms cubic crystals. It is malleable, ductile, and has superior strength and corrosion resistance. The metal is a fair conductor of heat and electricity and exhibits magnetic properties below 345°C.";
}
else if(i==4 && j==11)
{cout<<"Copper (Cu) in its pure form is a reddish-brown metallic element with high ductility and malleability that is an excellent conductor of heat and electricity: atomic weight 63.54; atomic number 29; density 8.94 g/cm3; melting point 1083°C; and boiling point 2595°C.";
}
else if(i==4 && j==12)
{cout<<"density – 7.13 g/cm³;\ncolor – bluish-white;\nmelting point – 420 °C;\nelasticity and malleability increase when heated to approximately 100 °C;\nboiling point of 906 °C;";
}
else if(i==4 && j==13)
{cout<<"Density 5.1 g.cm-3 at 20°C\nMelting point 29.8 °C\nBoiling point 2204 °C";
}
else if(i==4 && j==14)
{cout<<"Pure germanium is a hard, lustrous, gray-white, brittle metalloid. It has a diamondlike crystalline structure and it is similar in chemical and physical properties to silicon. Germanium is stable in air and water, and is unaffected by alkalis and acids, except nitric acid.";
}
else if(i==4 && j==15)
{cout<<"Properties and reactions. In its most stable elemental state, arsenic is a steel-gray, brittle solid with low thermal and electrical conductivity. Although some forms of elemental arsenic are metal-like, the element is best classified as a nonmetal.";
}
else if(i==4 && j==16)
{cout<<"Selenium may form halides by reacting vigorously with fluorine and chlorine, but the reactions with bromine and iodide are not as rapid. Selenium does not react directly with hydrogen fluoride or hydrogen chloride, but decomposes hydrogen iodide to liberate iodine and yield hydrogen selenide (Hoffmann and King 1997).";
}
else if(i==4 && j==17)
{cout<<"It is a dense liquid with a melting point of -7 ° Celsius and a boiling point of 58.9 ° Celsius. It is nonmetallic and heavy. Bromine evaporates easily at room temperature because it is a liquid. It has an unpleasant odor and is three times as dense as water.";
}
else if(i==4 && j==18)
{cout<<"Melting point 115.78 K (-157.37 °C, -251.27 °F)\nBoiling point 119.93 K (-153.415 °C, -244.147 °F)\nDensity (at STP) 3.749 g/L";
}

if(i==5 && j==1)
{cout<<"It is the second most electropositive metal.\nIt is soft and silvery.\nIt is highly inflammable.\nIt is mildly radioactive.";
}
else if(i==5 && j==2)
{cout<<"Strontium is a silvery-white, shiny metal. When exposed to air, it combines with oxygen to form a thin film of strontium oxide (SrO). The film gives the metal a yellowish color. Strontium has a melting point of about 757°C (1,395°F) and a boiling point of 1,366°C (2,491°F).";
}
else if(i==5 && j==3)
{cout<<"Yttrium is a silvery white, moderately soft, ductile metal. It is quite stable in air; rapid oxidation begins above approximately 450 °C (840 °F), resulting in Y2O3.";
}
else if(i==5 && j==4)
{cout<<"Zirconium is a very strong, malleable, ductile, lustrous silver-gray metal. Its chemical and physical properties are similar to those of titanium. Zirconium is extremely resistant to heat and corrosion. Zirconium is lighter than steel and its hardness is similar to copper.";
}
else if(i==5 && j==5)
{cout<<"Density – 8.57 g/cm3.\nAtomic Weight – 92.906 g/mol.\nCrystal Structure – Body Centered Cubic.\nMelting Point – 2750 K, 2477°C, 4491°F.\nBoiling Point – 5017 K, 4744°C, 8571°F.";
}
else if(i==5 && j==6)
{cout<<"Molybdenum (Mo) is a silvery transition metal renowned for its exceptional corrosion resistance and extremely high melting point.";
}
else if(i==5 && j==7)
{cout<<"Density 11.5 g.cm-3 at 20°C\nMelting point 2200 oC\nBoiling point 4877 oC";
}
else if(i==5 && j==8)
{cout<<"Ruthenium compounds are similar to those formed by the element cadmium. ...\nRuthenium compounds stain or discolor the skin.";
}
else if(i==5 && j==9)
{cout<<"Electronegativity according to Pauling 2.2\nDensity 12.4 g.cm-3 at 20°C\nMelting point 1970 °C";
}
else if(i==5 && j==10)
{cout<<"melting point 1,554.9 °C (2,830.8 °F)\nboiling point 2,963 °C (5,365 °F)\nspecific gravity 12.02 (0 °C [32 °F";
}
else if(i==5 && j==11)
{cout<<"silver (Ag), chemical element, a white lustrous metal valued for its decorative beauty and electrical conductivity.";
}
else if(i==5 && j==12)
{cout<<"Melting point 321 °Cb Decomposes at 357 °C\nBoiling point 765 °Cb No data\nDensity at 20 °C 8.65 g/cm3 at 25 °Cb 4.58 g/cm3 f";
}
else if(i==5 && j==13)
{cout<<"Indium is a soft, ductile, manleable, lustrous metallic metal. Its colour is silvery white and it has a face-centered tetragonal structure. It is liquid over a wide range of temperatures, like gallium that belongs to its same group. Both indium and gallium are able to wet glass.";
}
else if(i==5 && j==14)
{cout<<"Tin is a soft, malleable, ductile and highly crystalline silvery-white metal. When a bar of tin is bent a crackling sound known as the tin cry can be heard from the twinning of the crystals. Tin melts at about 232 °C (450 °F) the lowest in group 14.";
}
else if(i==5 && j==15)
{cout<<"Pure sulfur is a tasteless, odourless, brittle solid that is pale yellow in colour, a poor conductor of electricity, and insoluble in water. It reacts with all metals except gold and platinum, forming sulfides; it also forms compounds with several nonmetallic elements.";
}
else if(i==5 && j==16)
{cout<<"Tellurium is a chemical element with Te as its symbol. It belongs to group 16, periodic number 5 of the periodic table. Its atomic number is 52. Tellurium is a silvery-white semi-metallic element that is crystalline and brittle.";
}
else if(i==5 && j==17)
{cout<<"Iodine is a nonmetallic, nearly black solid at room temperature and has a glittering crystalline appearance. The molecular lattice contains discrete diatomic molecules, which are also present in the molten and the gaseous states. Above 700 °C (1,300 °F), dissociation into iodine atoms becomes appreciable.";
}
else if(i==5 && j==18)
{cout<<"It was the first noble gas found to form true chemical compounds. More than 4.5 times heavier than air, xenon is colourless, odourless, and tasteless.";
}

if(i==6 && j==1)
{cout<<"Cesium, gallium, and mercury are the only three metals that are liquid at or around room temperature.";
}
else if(i==6 && j==2)
{cout<<"Barium is a soft, silvery metal that rapidly tarnishes in air and reacts with water. Barium is not an extensively used element. Most is used in drilling fluids for oil and gas wells. It is also used in paint and in glassmaking.";
}
else if(i==6 && j==3)
{
cout<<"No element at this position";}
else if(i==6 && j==4)
{cout<<"Appearance: Colorless, fuming liquid.\nOdor: Acrid odor. Do not breathe fumes.\nSolubility: Infinitely soluble.\nSpecific Gravity: 1.15 -1.18.";
}
else if(i==6 && j==5)
{cout<<"Tantalum is a shiny, silvery metal which is soft when is pure. It is almost immune to chemical attack at temperatures below 150 C.";
}
else if(i==6 && j==6)
{cout<<"Tungsten is the heaviest engineering material with a density of 19.25 g/cm3. It has the highest melting point of all metals at 34108C with a boiling point of 57008C. It has the lowest vapour pressure of all metals. It has the highest modulus of elasticity of the metals (E = 400GPa).";
}
else if(i==6 && j==7)
{cout<<"Rhenium is a ductile, malleable, silvery metal. Ductile means capable of being drawn into thin wires. Malleable means capable of being hammered into thin sheets. It has a density of 21.02 grams per cubic centimeter, a melting point of 3,180°C (5,760°F), and a boiling point of 5,630°C (10,170°F).";
}
else if(i==6 && j==8)
{cout<<"Osmium is mainly found alloyed with other platinum metals, from which it is recovered commercially. The most important ores are either iridosmine and osmiridium. Iridosmine is a rare mineral found in Russia and in North and South America. Less of 100 kg are produced each year. There is little demand for the metal, which is difficult to fabricate";
}
else if(i==6 && j==9)
{cout<<"IRIDIUM: Nowadays demand for iridium comes mainly from the electronic industry, the automotive industry and from the chemical industry, where it is used to coat the electrodes in the chlor-alkali process, and in catalyst.";
}
else if(i==6 && j==10)
{cout<<"Platinum is a silver-white metal — it was once known as white gold. It is extremely resistant to tarnishing and corrosion (which makes it known as a noble metal) and is very soft and malleable, making it easy to shape; ductile, making it easy to stretch into wire; and unreactive, which means it doesn't oxidize";
}
else if(i==6 && j==11)
{cout<<"    Gold conducts heat and electricity. ...\nGold is ductile: It can be drawn out into the thinnest wire. ...\nGold is highly reflective of heat and light. ...\nGold is prized for its beauty. ...\n Gold is malleable, so it can be flattened into extremely thin sheets.";
}
else if(i==6 && j==12)
{cout<<"Mercury is a silvery-white, shiny metal, which is liquid at room temperature.";
}
else if(i==6 && j==13)
{cout<<"Thallium is very soft and melts easily. It is soft enough to cut with an ordinary knife and will leave a mark on paper if rubbed across it. Thallium has a melting point of 302°C (576°F) and a boiling point of 1,457°C (2,655°F). Its density is 11.85 grams per cubic centimeter.";
}
else if(i==6 && j==14)
{cout<<"Lead is a bluish-white lustrous metal. It is very soft, highly malleable, ductile, and a relatively poor conductor of electricity. It is very resistant to corrosion but tarnishes upon exposure to air. Lead isotopes are the end products of each of the three series of naturally occurring radioactive elements.";
}
else if(i==6 && j==15)
{cout<<"Bismuth is a soft, silvery metal with a bright, shiny surface and a yellowish or pinkish tinge. The metal breaks easily and cannot be fabricated (worked with) at room temperature. Its melting point is 271°C (520°F) and its boiling point is 1,560°C (2,480°F). Its density is 9.78 grams per cubic centimeter.";
}
else if(i==6 && j==16)
{cout<<"polonium (Po), a radioactive, silvery-gray or black metallic element of the oxygen group (Group 16 [VIa] in the periodic table).";
}
else if(i==6 && j==17)
{cout<<"Astatine is a highly radioactive element and it is the heaviest known halogen. Its chemical properties are believed to be similar to those of iodine. Is has been little researched because all its isotopes have short half lives.";
}
else if(i==6 && j==18)
{cout<<"Radon has a melting point of -71°C, boiling point of -61.8 °C, gas density of 9.73 g/l, specific gravity of the liquid state of 4.4 at -62°C, specific gravity of the solid state of 4, usually with a valence of 0 (it does form some compounds, however, such as radon fluoride).";
}


if(i==7 && j==1)
{cout<<"The melting point of francium is 27 °C, its boiling point is 677 °C, and its valence is 1. It is the second-least electronegative element, following cesium. It is the second rarest natural element, following astatine. Francium is the heaviest known member of the alkali metals series.";
}
else if(i==7 && j==2)
{cout<<"Radium is an alkaline earth metal. Radium has a melting point of 700°C, boiling point of 1140°C, specific gravity estimated to be 5, and valence of 2. Pure radium metal is bright white when freshly prepared, although it blackens upon exposure to air.";
}
else if(i==7 && j==3)
{cout<<"\n\nNo element at this position";
}
else if(i==7 && j==4)
{cout<<"Rutherfordium is a highly radioactive chemical element. His most stable isotope Rf 265 has an half like of approximately 13 hours. Nine of its isotopes are known.";
}
else if(i==7 && j==5)
{cout<<"The metal behaves as a solid at temperatures of 20o °C. It occurs as a synthetic element in nature, and it is artificially produced by the bombardment of the californium-249 with the nuclei nitrogen-1.";
}
else if(i==7 && j==6)
{cout<<"Seaborgium is an artificially produced radioactive chemical element, it's appearance is unknown, it probably has a silvery white or metallic gray colour. The most stable isotope Sg 271 has an half life of 2.4 minutes.";
}
else if(i==7 && j==7)
{cout<<"Bohrium is a chemical element with symbol Bh and atomic number 107. Classified as a transition metal, Bohrium is a solid at room temperature.";
}
else if(i==7 && j==8)
{cout<<"Hassium is a synthetic chemical element, expected to have chemical properties similar to those of osmium and a silvery white or metallic gray colour.";
}
else if(i==7 && j==9)
{cout<<"Meitnerium is a radioactive, synthetic element about which little is known. It is classified as a metal and is a solid at room temperature. Meitnerium has seven isotopes with known half-lives. The most stable is meitnerium-278 (278Mt), with a half-life of about eight seconds.";
}
else if(i==7 && j==10)
{cout<<"Darmstadtium is a chemical element with symbol Ds and atomic number 110. Classified as a transition metal, Darmstadtium is a expected to be a solid at room temperature.";
}
else if(i==7 && j==11)
{cout<<"From its position in the periodic table, in group 11 below gold, this element should have the physical properties of a noble metal and, were it long enough lived it should be possible to make compound of it although, like gold, it might be reluctant to form them. Its appearance is unknown, probably it is yellow or orange metallic (like gold).";
}
else if(i==7 && j==12)
{cout<<"Density 1.9 g.cm-3 at 20°C\nMelting point 28.4 °C\nBoiling point 669 °C";
}
else if(i==7 && j==13)
{cout<<"Nihonium is the temporary name of a chemical element in the periodic table that has the temporary symbol Nh and has the atomic number 113. It was discovered from the bombardment of atoms of Americium-243 with ions of calcium-48.";
}
else if(i==7 && j==14)
{cout<<"Flerovium Properties\nMelting Point: 70 °C, 160 °F, 340 K (predicted)\nBoiling Point: 150 °C,300 °F, 420 K (predicted)\nDensity: 22 g·cm3(predicted)";
}
else if(i==7 && j==15)
{cout<<"Moscovium is a synthetic chemical element with the symbol Mc and atomic number 115.";
}
else if(i==7 && j==16)
{cout<<"Livermorium is a chemical element with symbol Lv and atomic number 116. Classified as a post-transition metal, Livermorium is a expected to be a solid at room temperature.";
}
else if(i==7 && j==17)
{cout<<"Tennessine is a chemical element with symbol Ts and atomic number 117. Classified as a halogen, Tennessine is a expected to be a solid at room temperature.";
}
else if(i==7 && j==18)
{cout<<"Atomic Number: 118.\nAtomic Weight: 294.\nMelting Point: Unknown.\nBoiling Point: Unknown.";
}

if(i==8 && j==1)
{cout<<"No element at this position";
}
else if(i==8 && j==2)
{cout<<"\n\nNo element at this position";
}
else if(i==8 && j==3)
{cout<<"\n\nNo element at this position";
}
else if(i==8 && j==4)
{cout<<"Density	6.76 g.cm-3 at 20°C\nMelting point	799 °C\nBoiling point	3426 °C";
}
else if(i==8 && j==5)
{cout<<"melting point	931 °C (1,708 °F)\nboiling point	3,520 °C (6,368 °F)\nspecific gravity	6.773 (24 °C, or 75 °F)";
}
else if(i==8 && j==6)
{cout<<"melting point	1,021 °C (1,870 °F)\nboiling point	3,074 °C (5,565 °F)\nspecific gravity	7.008 (25 °C, or 77 °F)";
}
else if(i==8 && j==7)
{cout<<"Density	6.475 g.cm-3 at 20°C\nMelting point	1168 °C\nBoiling point	2460 °C";
}
else if(i==8 && j==8)
{cout<<"melting point	1,074 °C (1,965 °F)\nboiling point	1,794 °C (3,261 °F)\ndensity	7.520 g/cm3 (24 °C, or 75 °F)";
}
else if(i==8 && j==9)
{cout<<"Europium is a chemical element with symbol Eu and atomic number 63. Classified as a lanthanide, Europium is a solid at room temperature.";
}
else if(i==8 && j==10)
{cout<<"Gadolinium is a soft, shiny, ductile, silvery metal belonging to the lanthanide group of the periodic chart. The metal does not tarnish in dry air but an oxide film forms in moist air. Gadolinium reacts slowly with water and dissolves in acids.";
}
else if(i==8 && j==11)
{cout<<"Density	8.3 g.cm-3 at 20°C\nMelting point	1360 °C\nBoiling point	3041 °C";
}
else if(i==8 && j==12)
{cout<<"atomic weight	162.5\nmelting point	1,412 °C (2,574 °F)\nboiling point	2,567 °C (4,653 °F)";
}
else if(i==8 && j==13)
{cout<<"Density	9.2 g.cm-3 at 20°C\nMelting point	1522 °C\nBoiling point	2510 °C";
}
else if(i==8 && j==14)
{cout<<"Electronegativity according to Pauling	1.2\nDensity	9.3 g.cm-3 at 20°C\nMelting point	1545 °C";
}
else if(i==8 && j==15)
{cout<<"Density	7 g.cm-3 at 20°C\nMelting point	824 °C\nBoiling point	1466 °C";
}
else if(i==8 && j==16)
{cout<<"Density	9.7 g.cm-3 at 20°C\nMelting point	1663 °C\nBoiling point	3395 °C";
}
else if(i==8 && j==17)
{cout<<"No element at this position";
}
else if(i==8 && j==18)
{cout<<"No element at this position";
}

if(i==9 && j==1)
{cout<<"\n\nNo element at this position.";
}
else if(i==9 && j==2)
{cout<<"\n\nNo element at this position";
}
else if(i==9 && j==3)
{cout<<"\n\nNo element at this position";
}
else if(i==9 && j==4)
{cout<<"The fresh surface of the metal has a bluish-white luster. In many of its physical properties, thallium resembles its neighbor, lead.";
}
else if(i==9 && j==5)
{cout<<"Atomic number	91\nDensity	15.37 g.cm-3 at 20°C\nMelting point	1600 °C";
}
else if(i==9 && j==6)
{cout<<"Uranium is a hard, dense, malleable, ductile, silver-white, radioactive metal. Uranium metal has very high density. When finely divided, it can react with cold water. In air it is coated by uranium oxide, tarnishing rapidly.";
}
else if(i==9 && j==7)
{cout<<"Density	20.2 g.cm-3 at 20°C\nMelting point	640 °C\nBoiling point	3902 °C";
}
else if(i==9 && j==8)
{cout<<"The physical properties of polyurethane are considerable. Polyurethane performs well for hardness, tensile strength, compression strength, impact resistance, abrasion resistance and tear strength.";
}
else if(i==9 && j==9)
{cout<<"Density	13.67 g.cm-3 at 20°C\nMelting point	994 °C\nBoiling point	2607 °C";
}
else if(i==9 && j==10)
{cout<<"Atomic number	96\nDensity	13.51 g.cm-3 at 20°C\nMelting point	1340 °C\nBoiling point	unknown";
}
else if(i==9 && j==11)
{cout<<"Electronegativity according to Pauling	unknown\nDensity	14 g.cm3 at 20°C\nMelting point	unknown";
}
else if(i==9 && j==12)
{cout<<"Physical state at 20°C	Gas\nMelting point	–110°C (166°F)\nBoiling point at 1 atm	–22.5°C (8.5°F)";
}
else if(i==9 && j==13)
{cout<<"Melting Point:	860 °C, 1580 °F, 1133.15 K\nDensity:	8.84 g/cm3\nLiquid Density @ Melting Point:	N/A\nDensity @ 20°C:	8.84 g/cm3";
}
else if(i==9 && j==14)
{cout<<"Fermium is a synthetic element with the symbol Fm and atomic number 100.";
}
else if(i==9 && j==15)
{cout<<"Atomic Mass Average: 258.\nBoiling Point:\nCoefficient of lineal thermal expansion/K-1: N/A.";
}
else if(i==9 && j==16)
{cout<<"Density	1.3402 g/L\nMelting point	-164 °C (-263 °F; 109 K)\nBoiling point	-152 °C (-242 °F; 121 K)";
}
else if(i==9 && j==17)
{cout<<"Color	Unknown, but probably metallic and silvery white or grey in appearance\nClassification	Metallic\nMelting point	1900 K (1627°C or 2961°F)";
}
else if(i==9 && j==18)
{cout<<"No element at this position";
}




return 0;
}



int main()
{
int i,j,userchoice;
setColor(blue, black);
   cout<<"\n\t\t\tTHE MODERN PERIODIC TABLE\n";
  
    cout<<"\t\t\t-------------------------\n";
    setColor(blue, black);
    cout<<"\t  1                                                      18\n\n";
    cout<<"\t1 H  2                                  13 14  15 16  17 He"<<"\n\n";
    cout<<"\t2 Li Be                                 B  C   N  O   F  Ne"<<"\n\n";
    cout<<"\t3 Na Mg 3  4  5  6  7  8  9  10 11  12  Al Si  P  S   Cl Ar"<<"\n\n";
    cout<<"\t4 K  Ca Sc Ti V  Cr Mn Fe Co Ni Cu  Zn  Ga Ge  As Se  Br Kr"<<"\n\n";
    cout<<"\t5 Rb Sr Y  Zr Nb Mo Tc Ru Rh Pd Ag  Cd  In Sn  Sb Te  I  Xe"<<"\n\n";
    cout<<"\t6 Cs Ba    Hf Ta W  Re Os Ir Pt Au  Hg  Tl Pb  Bi Po  At Rn"<<"\n\n";
    cout<<"\t7 Fr Ra    Rf Db Sg Bh Hs Mt Ds Rg  Cn  Nh Fl  Ma Lv  Ts Og"<<"\n\n\n";
    setColor(magenta, black);
    cout<<"\t\t 8 La Ce Pr Nd Pm Sm Eu Gd  Tb  Dy Ho  Er Tm  Yb Lu"<<"\n\n";
    cout<<"\t\t 9 Ac Th Pa U  Np Pu Am Cm  Bk  Cf Es  Fm Md  No Lr"<<"\n\n\n";
   
    while(i!=-99 || j!=-99)
    {
    	setColor(red, black);
    cout<<"\n\n\tEnter -99 to either period or group to end.\n";
    setColor(white, black);
    cout<<"\n\tEnter the PERIOD of the element: ";
    cin>>i;
    cout<<"\tEnter the GROUP of the element: ";
    cin>>j;
   
    if(i==-99 || j==-99)
{
	setColor(yellow, black);
cout<<"\n\n\tTHANKYOU!\n";
setColor(white, black);
    
return 0;}
 
 if(i<=0 || i>=10 || j<=0 || j>=19)
 {setColor(red, black);
 	cout<<"\n\tEither the Group or period entered is Incorrect!";
 }

else{
	setColor(green, black);
    cout<<"\n\nWhat do you want to find about the element?\n1. Origin of the element\n2. Physical Properties\n\n";    
    cin>>userchoice;
    switch(userchoice)
    {
    case 1:
    {Origin(i,j);
    break;
    }
    case 2:
    {
    physical(i,j);
    break;
    }
   default:
   	{
   		setColor(red, black);
	   cout<<"Enter a valid option!";
 		break;
 	}
   
    }
   
   
    }
    }
return 0;
}
