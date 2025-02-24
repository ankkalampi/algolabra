## Huomioita

- arkkitehtuuri seuraavanlainen: komponentteja käsittelevät ecs-järjestelmät muotoa x_system.hpp. Näiden lisäksi managerit (esim render_manager) huolehtivat enginen perustehtävistä -> rendermanager koostaa renderöitävät tekstuurit rendersystemin perusteella ja renderöi ne, runtime manager hoitaa game loopin ajojärjestyksen jne
- managereita voisi olla:
    - render_manager (tekstuurien muodostus, renderöinti, ikkuna)
    - runtime_manager (ecs-järjestelmät, game loop)
    - world_manager (cell-koordinaatisto, terrain)
    - load_manager (entityjen ja maailman lataaminen json-tiedostoista)
- mahdollisesti engine-luokka, joka kokoaa sovelluksen toiminnan aloituksesta sulkemiseen
- kaikki globaalit muuttujat tullaan kapseloimaan managereihin 
- globals.hpp:n arvot voidaan lukea tiedostosta, ja tallentaa esim engine-luokkaan