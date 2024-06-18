## Project Serenity

### Prototype
The concept of the lantern is that it glows brighter as the user approaches it and dims as the user leaves. This effect was achieved using two ESP-32s, communicating via the ESP-NOW Wireless Communication Protocol. 

The master circuit is outside of the lantern, attached to the boardwalk in the pond. Using an ultrasonic sensor, the distance between the user and the sensor is sent to the slave circuit inside the tank which control the light encapsulated by the tank.  

When the user walks past the pond entrance, the lanterns are dim but pulsating — inciting curiosity. With multiple installations placed around the pond, the lanterns dim and brighten dyanmically with the user's path. The lantern's light attracts fishes to swim into the lantern and the shadows will be casted on the lantern. As more fishes enter the lantern, their silhouettes interweave and creates a unique cast on the faces of the lanterns.

### Scale Model
A scale model of the SUTD pond with our lanterns was a part of our deliverables as well. An Arduino Uno controlled the lights, allowing us to manually dim and brighten each lantern's light with a potentiometer. 