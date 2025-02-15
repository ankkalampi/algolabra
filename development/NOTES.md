## Huomioita

- Arkkitehtuuri on kehittymässä seuraavanlaiseen suuntaan:
    pyritään pääsemään globaaleista muuttujista eroon, ja kapseloidaan eri moduulien toimintalogiikka structeihin tai luokkiin. Poikkeuksena globals.hpp. Arvojen lukemista jostain config.txt-tiedostosta voisi miettiä.
- entityt ja populaatiot totetutettava templateilla. mietittävä, mitä tarkalleen ottaen kumpaankin tulee. olisiko järkevää pitää vain update populationissa, ja add/remove entityssä
- extern template struct Population<Animal>:in deklarointi ei toimi, tulee ilmeisesti jonkinlaisia circular include -ongelmia. tämä selvitettävä