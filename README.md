# Neural Animals - Neuroverkkojen ja geneettisen algoritmin ohjastama yksinkertainen ekosysteemisimulaatio

Tässä projektissa on tarkoituksena toteuttaa ekosysteemisimulaatio, jossa virtuaalieläimet pyrkivät lisääntymään ympäristössä, jossa niitä uhkaa nälkiintymisen lisäksi myös verenhimoiset lihansyöjät, sekä lisääntymismahdollisuuksista kilpailevat toiset saman lajin edustajat.

Tämä projetki käyttää seuraavia ulkoisia kirjastoja:
- SDL2 -> grafiikan piirtäminen, ikkunan avaaminen 
- libnoise -> perlin-kohinan muodostaminen maailman generointia varten

Projektia pääsee testailemaan omalla koneella (Debian-pohjaisella Linuxilla) seuraavasti:

1. Kloonaa projekti itsellesi

´´´
git clone git@github.com:ankkalampi/algolabra.git
´´´

2. Asenna tarvittavat riippuvuudet

´´´
sudo apt update
sudo apt install libsdl2-dev
sudo apt install libnoise-dev
´´´

3. Anna brun.sh:lle ajo-oikeudet (kääntää ja ajaa ohjelman)

´´´
cd algolabra
sudo chmod +x brun.sh
´´´

4. suorita brun.sh (kääntää ja ajaa ohjelman)

´´´
./brun.sh
´´´ 
