## Seuraavaksi tehtävää (backlog):

### World:
- ~~Worldin terrainin generointi siten, että muodostuu parametrien perusteella yhtenäisiä alueita, eikä pelkkää noisea~~
- Worldin asuttaminen eläimillä ja kasveilla

### App(Runtime):
- ~~appin runtimen alustus (maailman luonti jne)~~
- ~~pääloopin pyörittäminen (simulaatio ja inputin kuuntelu)~~
- mahdollisesti engine-luokka, joka kapseloi enginen ominaisuudet ja parametrit

### Renderöinti:
- ~~Terrainin renderöinti~~
- ~~Terrainin renderöinti tekstuuriin (nopeuttaa huomattavasti)~~
- Eläinten renderöinti
- Eläinten iän ja sukukypsyyden näkyminen
- ~~Kasvien renderöinti~~
- Kasvien iän näkyminen
- Kasvien myrkyllisyyden näkyminen

### Eläimet ja kasvit:
- Eläinten aistiminen naapuriruutuihin ja kauemmas
- Eläinten liikkuminen ja toiminnot (syöminen, lisääntyminen)

### Neuroverkot:
- Neuroverkkojen toteutus
- Neuroverkkojen yhdistäminen eläimiin
- Neuroverkkojen tehokas paralleeli laskenta

### Geneettinen algoritmi:
- millä perusteella geenit muodostuvat?
- millä perusteella geenit periytyvät?
- millä perusteella geenit mutatoituvat?

### Refaktorointi:
- ~~World omaan tiedostoonsa~~
- Eläimet omaan tiedostoonsa
- Kasvit omaan tiedostoonsa
- ~~Runtime omaan tiedostoonsa~~
- Neuroverkko omaan tiedostoonsa
- Geneettinen algoritmi omaan tiedostoonsa
- ~~Renderöinti omaan tiedostoonsa~~
- UI omaan tiedostoonsa
- Eroon globaaleista extern-muuttujista, eri moduulien kapselointi
- mahdollisesti config.txt-tiedoston lukeminen

### UI (jos aikaa):
- alkuvalikko, jossa kentät/sliderit alkuparametreille, sekä start-nappula
- simulaatioruudussa ajan pysäytys, nopeutus, hidastus
- simulaatioruudussa back-nappula takaisin alkuvalikkoon
- simulaatioruudussa datanäkymä (esim eri eliöiden määrä, keski-ikä jne)
- simulaatioruudussa ehkä mahdollisuus klikata oliota ja tarkastella sen neuroverkkoa
