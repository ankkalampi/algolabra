## Huomioita

- Arkkitehtuuri on kehittymässä seuraavanlaiseen suuntaan:
    Lähtökohtaisesti on olemassa namespace, ja namespacella extern-muuttujia ja funktioita. Olioksi kapseloiminen on perusteltua, jos extern-muutujia tulisi muuten hirvittävä määrä (esim world)
- entityt ja populaatiot totetutettava templateilla. mietittävä, mitä tarkalleen ottaen kumpaankin tulee. olisiko järkevää pitää vain update populationissa, ja add/remove entityssä
- extern template struct Population<Animal>:in deklarointi ei toimi, tulee ilmeisesti jonkinlaisia circular include -ongelmia. tämä selvitettävä