# 42_so_long

42_so_long est un projet de l'école 42 dans lequel nous devons créer un jeu 2D afin de nous familiariser avec les textures, les sprites et des éléments de gameplay basiques.
Dans ce jeu nous controllons un personnage qui va devoir collecter tous les objets de la carte avant de pouvoir quitter les lieux.

## 📋 Règles

### 🗺️Carte
Le programme lit un fichier, la carte du jeu, qui lui sera passé en paramètre.  
Vous pouvez créer n'importe quel carte mais elle doit respecter certaines règles :
 * L'extension du fichier doit être `.ber`
 * Il doit etre rectangulaire et toutes les bords de la carte doivent être de type 1
 * Il ne peut avoir que 1 personnage, au moins 1 sortie et au moins 1 objet collectable.
 * Caractères autorisés :

| Caractère  | Objet                          | Précision                                                                                              |
| ---------- | ------------------------------ | ------------------------------------------------------------------------------------------------------ |
| 1          | Obstacle                       | Case infranchissable par le personnage ou les ennemies                                                 |
| 0          | Vide                           | Case où peuvent se déplacer le personnage ou les ennemies                                              |
| C          | Collectible                    | Objet que le personnage doit rammasser                                                                 |
| E          | Sortie                         | Case sortie que le personnage peut emprunter seulement quand il a récupérer tous les collectibles      |
| P          | Position de départ personnage  | Case sur laquelle se trouve le joueur au démarage du jeu                                               |
| V          | Position de départ ennemie     | Case sur laquelle se trouve un ennemie au démarage du jeu (ennemie présent que dans la partie ✨bonus) |

### ⌨️ Contrôles
* Les touches **W**, **A**, **S**, **D** (qwerty) ou **Z**, **Q**, **S**, **D** (azerty) servent à déplacer le personnage
* La touche **ESC** ferme la fenêtre et quitte le programme

### ✨Bonus
* Ennemies présents sur la carte qui font perdre le joueur s'ils le touchent
* Animation de sprite
* Nombre de mouvement affiché sur l'écran


![alt-text](https://github.com/Ismerie/so_long/blob/master/gif/preview.gif)

## 🛠️ Usage
Avant d'exécuter le projet, vous devez configurer votre MinilibX (c'est notre bibliothèque graphique). Vous trouverez ici tout ce dont vous avez besoin pour faire fonctionner la bibliothèque selon votre OS <https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#installation>.

Si vous utilisez ***mlx_linux***, assurez-vous que MinilibX fonctionne en exécutant un test. Utilisez make ```mlx_linux``` puis exécutez le le test avec :
```
./mlx_linux/test/run_tests.sh
```

Si le test fonctionne, faites maintenant attention aux lignes suivantes dans le Makefifle :
```
INCLUDE_LINUX = -Ilibft/ -I/usr/include -Imlx_linux
LES_LIBS_LINUX = -Llibft -lft -Lmlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

INCLUDE_MAC = -Ilibft/ -Imlx_mac
LES_LIBS_MAC = -Llibft -lft -Lmlx_mac -lmlx -framework OpenGL -framework AppKit
```
Vous devez choisir la bonne configuration en fonction de la structure de votre système et de votre OS. Je vous recommande de suivre le lien que je vous ai fourni ci-dessus. Si vous utilisez ***mlx_linu***x, le droit ```-I/usr/*/include``` et ```-L/usr/*/lib``` doit correspondre à la première ligne ```INC=/usr/*/include``` du ```libmlx/Makefile.gen``` fichier.  
Sinon si vous utilisez **libmlx_mac**, vous devez modifier le paramètre LIBMLX avec cette ligne ```LIBMLX = libmlx_mac```.

Si tout semble correct, utilsiez la commande ```make``` pour compiler le projet puis exécutez le programme avec :
```
./so_long Map/medium.ber
```

Pour exécuter la partie bonus, utilisez la commande ```make bonus``` et exécutez le programme bonus avec :
```
./so_long_bonus Map/medium_bonus.ber
```
SI vous avez un clavier **QWERTY**, vous pouvez modifier les touches dans ```srcs/so_long.h``` et dans ```srcs/so_long_bonus.h```
