Project: Jednoduchý 2D simulátor mobilních robotů.
Předmět: ICP
Autoři: Ondřej Beneš    (xbenes61)
        David Zatlokal  (xzatlo27)

Cílem projektu bylo vytvořit jednoduchý simulátor robotů v jazyce C++ za použití toolkitu Qt.
Výsledný program umožňuje za pomoci uživatelského rozhranní načíst uloženou simulaci, přidat nový objekty do probíhající simulace, simulaci pozastavit, nebo aktuální nastavení simulace uložit do souboru.
Soubory s uloženými daty simulace jsou ve formátu json a obsahují dva typy objektů - roboty a překážky. Soubor je možné ručně upravit a poté ho pomocí uživatelského rozhranní načíst a spustit.
V průběhu simulace se prostředím pohybují roboti o dané velikosti (parametr robota), kteří reagují na detekci překážky v dané vzdálenosti (parametr robota) otočením o daný úhel (parametr robota) daným směrem (parametr robota), načež pokračují v pohybu novým směrem.
Speciálním typem robota je ovladatelný robot, kterého je možné ovládat pomocí tlačítek v okně simulace. Roboti jsou podle typu barevně rozlišeni a detekci překážky dávají najevo změnou barvy na červeno.