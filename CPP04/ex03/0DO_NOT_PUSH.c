/*

Pour comprendre comment cela fonctionne du point de vue de l'ordinateur, 
imaginez qu'il existe une table appelée "tableau des fonctions virtuelles" 
(parfois appelée table de vtables). Cette table contient des pointeurs de fonction vers 
les implémentations des méthodes virtuelles de la classe. 
Lorsque vous appelez une méthode virtuelle sur un objet, le compilateur génère du code qui va 
chercher dans cette table pour trouver la bonne implémentation de la méthode à appeler, 
en fonction du type réel de l'objet à l'exécution.

En termes de compilation, le compilateur génère généralement des tables de fonctions virtuelles pour 
chaque classe qui en a besoin. Ces tables sont utilisées pour résoudre dynamiquement les 
appels de méthode à l'exécution. La résolution dynamique se produit donc au moment de l'exécution, 
lorsque le programme est en cours d'exécution, et non au moment de la compilation.

dès qu'une classe déclare au moins une méthode virtuelle, le compilateur génère généralement une table 
de fonctions virtuelles pour cette classe. Cela s'applique que la méthode virtuelle soit pure ou non.

*******************************

classe abstraite pure : interfaces

Cela permet de spécifier un ensemble de méthodes que les classes dérivées doivent implémenter, 
sans fournir d'implémentation par défaut. Cela favorise une conception par interface plutôt que par 
implémentation, ce qui rend le code plus flexible et plus facile à maintenir.





*/

////////////////////////////////////////////////////////

/*
    Conception par interface : Lorsque l'on conçoit par interface, on se concentre sur la spécification des comportements et des fonctionnalités que les classes doivent fournir, plutôt que sur les détails de leur implémentation interne. Une interface définit un contrat ou un ensemble de méthodes que les classes doivent implémenter, mais elle n'impose pas de contraintes sur la façon dont ces méthodes sont réalisées. En d'autres termes, une interface fournit une abstraction de haut niveau qui masque les détails de l'implémentation sous-jacente. Les classes qui implémentent cette interface peuvent le faire de différentes manières, tant qu'elles respectent le contrat défini par l'interface. Cela permet une grande flexibilité dans la conception du système, car les détails d'implémentation peuvent être modifiés sans affecter l'interface publique.

    Conception par implémentation : En revanche, la conception par implémentation se concentre davantage sur la manière dont les fonctionnalités sont réalisées et implémentées dans le code. Elle expose souvent les détails internes des classes, ce qui peut rendre le code plus rigide et plus difficile à maintenir. Lorsque l'on conçoit par implémentation, les détails de l'implémentation sont souvent étroitement couplés aux autres parties du système, ce qui rend les modifications et les évolutions plus difficiles à gérer. Les changements dans une partie de l'implémentation peuvent nécessiter des modifications dans plusieurs autres parties du code, ce qui peut introduire des erreurs et des fragilités.

	Ainsi, en favorisant une conception par interface plutôt que par implémentation, on privilégie une approche plus flexible et modulaire. Cela permet de réduire le couplage entre les différentes parties du système, ce qui rend le code plus facile à comprendre, à étendre et à maintenir. En utilisant des interfaces et des méthodes virtuelles pures en C++, on peut définir des contrats clairs entre les différentes parties du système, favorisant ainsi une conception orientée objet plus robuste et plus évolutive.
*/