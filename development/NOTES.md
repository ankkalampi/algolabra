## Huomioita

- Arkkitehtuuri on kehittymässä seuraavanlaiseen suuntaan:
    pyritään pääsemään globaaleista muuttujista eroon, ja kapseloidaan eri moduulien toimintalogiikka structeihin tai luokkiin. Poikkeuksena globals.hpp. Arvojen lukemista jostain config.txt-tiedostosta voisi miettiä.
- entityt ja populaatiot totetutettava templateilla. mietittävä, mitä tarkalleen ottaen kumpaankin tulee. olisiko järkevää pitää vain update populationissa, ja add/remove entityssä
- populationin metodeissa mietittävä, mikä voi olla const, ja mikä ei voi olla const tällä hetkellä add-funktio ei ole const, koska testitkään eivät ole. pitää huomioida tämä muita metodeja testattaessa