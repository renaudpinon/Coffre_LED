#include <Adafruit_NeoPixel.h>

// Defines:

// Numéro de broche du neopixel:
#define kPinNeopixel            10

// Nombre de leds sur le NeoPixel:
#define kNumPixels      12

#define kSteps        0.01
#define kDelay          20

// Variables globales:

// Phase ascendante ou descendante:
bool _makeBrighter = true;

// Objet NeoPixel:
Adafruit_NeoPixel _pixels = Adafruit_NeoPixel(kNumPixels, kPinNeopixel, NEO_GRB + NEO_KHZ800);

// pourcentage de la valeur cible (0.0 à 1.0):
float _factor = 0.0;

// Couleurs RVB cibles:
int _rTarget = 0;
int _gTarget = 0;
int _bTarget = 0;

// Prototypes:

void SetTargetColor();
void PixelsLoop();

// Fonctions:

/**
 * Initialisation
 */
void setup()
{
	_pixels.begin(); // Initialise les NeoPixels.
	
	// initialise le générateur de nombre aléatoire:
	randomSeed(analogRead(0));
	
	// Définit la première couleur RGB:
	SetTargetColor();
}

/**
 * Boucle principale
 */
void loop()
{
	PixelsLoop();
}

/**
 * Obtient une couleur cible aléatoire
 */
void SetTargetColor()
{
	_rTarget = random(256); // 0 à 255.
	_gTarget = random(256);
	_bTarget = random(256);
}

/**
 * Allume les pixels suivant la progression vers la couleur cible
 */
void PixelsLoop()
{
	// On obtient le nouveau % de couleur cible:
	_factor += (_makeBrighter) ? kSteps : -kSteps;
	
	// Passe si nécessaire en phase descendante:
	if (_factor >= 1.0)
	{
		_factor = 1.0;
		_makeBrighter = false;
	}
	
	// Obtient les couleurs RVB par rapport au
	// pourcentage de couleurs cibles:
	int r = _rTarget * _factor;
	int g = _gTarget * _factor;
	int b = _bTarget * _factor;
	
	// Allume toutes les LEDs de la même couleur:
	for (int i = 0 ; i < kNumPixels ; i++)
	{
		_pixels.setPixelColor(i, _pixels.Color(r, g, b));
	}
	_pixels.show();  // met à jour les couleur des LEDS.
	
	// Si fin de phase descendante:
	if (_makeBrighter == false && _factor < kSteps)
	{
		// Phase ascendante:
		_factor = 0.0;
		_makeBrighter = true;
		
		// Obtient la nouvelle couleur:
		SetTargetColor();
	}
	
	delay (kDelay);
}
