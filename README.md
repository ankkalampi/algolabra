# Neural Animals - Neuroverkkojen ja geneettisen algoritmin ohjastama yksinkertainen ekosysteemisimulaatio

Tässä projektissa on tarkoituksena toteuttaa ekosysteemisimulaatio, jossa virtuaalieläimet pyrkivät lisääntymään ympäristössä, jossa niitä uhkaa nälkiintymisen lisäksi myös verenhimoiset lihansyöjät, sekä lisääntymismahdollisuuksista kilpailevat toiset saman lajin edustajat.

Tämä projekti käyttää seuraavia ulkoisia kirjastoja:
- SDL2 -> grafiikan piirtäminen, ikkunan avaaminen 
- libnoise -> perlin-kohinan muodostaminen maailman generointia varten
- google test -> testaus

Projekti vaatii Linux-käyttöjärjestelmän lisäksi:
- C++ -kääntäjän (vähintään C++17)
- CMake (vähintään versio 3.1)

Jos CMake ei ole asennettuna, sen voi asentaa Debian-pohjaisessa käyttöjärjestelmässä (esim Ubuntu) seuraavasti:

```
sudo apt install cmake
```

Projektia pääsee testailemaan omalla koneella seuraavasti:

1. Kloonaa projekti itsellesi

```
git clone git@github.com:ankkalampi/algolabra.git
```

2. Anna brun.sh:lle ajo-oikeudet (kääntää ja ajaa ohjelman)

```
cd algolabra
sudo chmod +x brun.sh
```

3. suorita brun.sh vivulla -b (kääntää ohjelman) tai -br (kääntää ja ajaa ohjelman)

```
./brun.sh -br
``` 

brun.sh ja cmake huolehtivat riippuvuuksien lataamisesta, kääntämisestä yms. Yhteensopivuusongelmien välttämiseksi ja sovelluksen toiminnan kokeilun helpottamiseksi kaikki riippuvuudet asennetaan build-prosessin yhteydessä projektikansioon. Niiden ei siis pitäisi jäädä kummittelemaan koneelle sen jälkeen kun projektikansio on poistettu. Projektikansion kooksi muodostuu noin 150MB, kun riippuvuudet on haettu ja sovellus käännetty.

brun.sh: eri vipuvaihtoehdot:

- -b -> kääntää ja ajaa ohjelman (build and run)
- -c -> poistaa build-kansion kokonaan ja kääntää projektin ja riippuvuudet (clean build)
- -r -> ajaa ohjelman (projekti on oltava käännetty joko -b tai -c -vivulla)
- -t -> ajaa testit (projekti on oltava käännetty joko -b tai -c -vivulla)
- ei vipua -> ajaa vain ajotiedoston (projekti on oltava käännetty joko -b tai -c -vivulla)

vipuja voi yhdistää siten, että ensimmäinen vipu on joko -b tai -c ja jälkimmäinen on joko -r tai -t. Eli on siis mahdollista ainoastaan ajaa ohjelma tai testit, tai ainoastaan kääntää ohjelma, tai suorittaa molemmat toiminnot samalla kertaa.
