# BE_microControleur

## Projet Voilier

Ce projet concerne la création et la programmation d'une maquette de voilier, visant à automatiser la gestion de l'écoute sur un voilier de modélisme. Il s'agit d'une initiative menée dans le cadre d'un cours portant sur les microcontrôleurs et les périphériques.

### Objectif
L'objectif principal de ce projet était de développer un système embarqué permettant de simplifier le pilotage d'un voilier de modélisme pour les débutants. Cela impliquait la création d'un système capable de gérer automatiquement l'écoute sur le voilier, quelle que soit sa direction (cap), en utilisant un microcontrôleur STM32F103.

### Fonctionnalités
Le voilier offre les fonctionnalités suivantes :
- **Bordage Automatique** : Réglage automatique de l'angle des voiles en fonction de l'angle du vent par rapport à l'axe longitudinal du bateau.
- **Orientation du Voilier** : Contrôle du plateau supportant le bateau pour changer la direction du voilier via une télécommande.
- **Système Anti-Chavirement** : Détection et relâchement des voiles si l'angle de roulis dépasse 40° pour ramener le voilier à l'horizontal.
- **Transmission d'Informations** : Envoi d'alertes en cas de situation critique (détection limite du roulis, faible tension de batterie) et envoi régulier d'informations sur l'angle d'ouverture des voiles ou l'allure du bateau.
- **Transmission de l'Heure** : Envoi de l'heure avec les informations envoyées vers la télécommande.

### Langage de Programmation
Ce projet a été réalisé en langage C pour la programmation du microcontrôleur STM32F103, en utilisant les drivers codés par nous-mêmes pour le contrôle des périphériques et des capteurs.

### Structure du Code
Le code source est organisé en services logiciels correspondant à chaque fonctionnalité du voilier. Chaque service est conçu pour gérer spécifiquement une partie du système, ce qui facilite la maintenance et les évolutions futures du projet.




