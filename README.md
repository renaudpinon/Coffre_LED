# Coffre_LED

This repository is only made for the article "Coffre à bouteille lumineux" published in the french magazine Programmez!


Coffre avec illumination NeoPixel Ring à l'ouverture (magazine Programmez!)

Vous trouverez ici tous les fichiers de support de l'article "Arduino: un coffre lumineux pour l'été !" du magazine Programmez!

- coffre_LED.ino : fichier code source du projet
- Coffre_Leds.f3d : fichier Fusion 360 du projet
- Cale.f3d : fichier Fusion 360 de la cale servant à appuyer le switch à la fermeture du couvercle du coffre
- Base.stl : fichier d'impression 3D pour la base du boitier
- Couvercle.stl : fichier d'impression 3D pour le couvercle du boitier
- Cale.stl : fichier d'impression 3D pour la cale servant à appuyer le switch à la fermeture du couvercle du coffre
- ListeCourses.pdf : tableau présentant les pièces du projet, leur prix indicatif ainsi qu'un lien pour les télécharger
- coffre_breadboard.png : schéma électronique de montage
- img0004.jpg : image d'illustration
- coffre.png : image d'illustration

# Notes sur les fichiers .f3d

J'ai inclus les fichiers pour que vous puissiez les modifier au cas où vos modules n'aient pas exactement la même dimension que les miens. Si vous voulez modifier les fichiers, ne touchez pas aux faces mais modifiez simplement les dessins (sketches) et les dimensions se trouveront modifiées automatiquement. De la même façon, si vous devez changer la hauteur d'extrusion des pièces, double-cliquez simplement sur les icônes d'extrusion dans la barre d'historique en bas et changez la distance d'extrusion à votre convenance.

Enfin, vous remarquerez qu'il n'y a pas de trou pour laisser passer la lumière des NeoPixels : c'est parce que je possède un filament "Blanc naturel" qui, lorsque l'épaisseur est inférieure ou égale à 1mm, laisse totalement passer la lumière. Ce ne sera en revanche pas forcément votre cas, notamment si vous avez un filament coloré.
Dans ce cas vous pouvez très simplement ajourer la zone du couvercle devant les NeoPixels de la façon suivante : dans Fusion 360, cliquez sur le menu "Modify/Change parameters". Une nouvelle fenêtre s'ouvre avec un tableau : repérez le paramètre "Epaisseur_zone_LED" et dans la case "Expression" remplacez "0.6 mm" par "1.6 mm". Cela aura pour effet de totalement ajourer la zone. Notez qu'il est dans ce cas conseillé de coller une surface transparente à cette endroit pour éviter au maximum une projection malencontreuse de liquide sur le circuit !

Have fun !