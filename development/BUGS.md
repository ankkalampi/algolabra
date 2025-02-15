## Tiedettyjä bugeja:

- ~~renderWorld ei ilmeisesti toimi kunnolla, jos maailma ei ole neliö. Koordinaattien laskennassa jotain häikkää. Vika voi olla muuallakin~~
- ~~createStartingPlants ei toimi kunnolla: tiputtaa world.plantsin koon yhteen kun kierroksia käyty numberPlants~~
- extern template struct Population<Animal>:in deklarointi ei toimi, tulee ilmeisesti jonkinlaisia circular include -ongelmia. tämä selvitettävä
