# image-filter
Uses data and memory management to apply filter to an image
To make a filter, the program have to go through all pixels in the image and change them, these are the available filters:

#### Grayscale:
To make a grayscale filter you need to make every Red, Green and Blue value of a pixel be the same, using the average value of the three. 

![image](https://github.com/Aeziren/image-filter/assets/123553708/49c7547f-16cf-4932-84b1-34ee426f7523) R: 180, G: 40, B: 90 => ![image](https://github.com/Aeziren/image-filter/assets/123553708/1636b94c-438b-4605-9a29-704293bbbb9c) R: 103, G: 103, B: 103

#### Sepia
An image can be converted to sepia by taking each pixel, and computing new red, green, and blue values based on the original values of the three.

Using the following formula:

![image](https://github.com/Aeziren/image-filter/assets/123553708/762db45e-8ba5-43c7-aed5-fba386aa2c24)

![image](https://github.com/Aeziren/image-filter/assets/123553708/04159aa8-12ea-452d-9c10-8115a2d9adf0) R: 10, G: 166, B: 245 => ![image](https://github.com/Aeziren/image-filter/assets/123553708/9a207382-21bd-45e0-8a0f-10324a7df8a5) R: 177, G: 158, B: 123

#### Reflection
The resulting image is what you would get by placing the original image in front of a mirror.
To create this filter you need to swap the value of the first pixel with the last, the second with the last but one and so on and so forth.

#### Blur
We’ll use the [box blur](https://en.wikipedia.org/wiki/Box_blur), which works by taking each pixel and, for each color value, giving it a new value by averaging the color values of neighboring pixels.

![image](https://github.com/Aeziren/image-filter/assets/123553708/0ddad4d1-b175-4c19-ae53-35a90de97885)


## Examples
We'll use the following image as example:

![image](https://github.com/Aeziren/image-filter/assets/123553708/0513378e-4d2f-4f9f-984c-b427008bec61)


#### Grayscale
![image](https://github.com/Aeziren/image-filter/assets/123553708/c872bddf-7f87-421f-800a-799b71a7f614)

![image](https://github.com/Aeziren/image-filter/assets/123553708/6ee915d3-2bf6-4043-aec0-e98e609519e6)

#### Sepia
![image](https://github.com/Aeziren/image-filter/assets/123553708/b3073eb3-7e4a-4654-9511-8efe425725ac)

![image](https://github.com/Aeziren/image-filter/assets/123553708/fe142df8-f5fe-4431-8336-a126373c243e)

#### Reflection
![image](https://github.com/Aeziren/image-filter/assets/123553708/ff486023-5b41-408d-af88-54b5b7f4e3ed)

![image](https://github.com/Aeziren/image-filter/assets/123553708/6191dcd5-9bcf-4b19-8bfa-f3b82ed3e960)

#### Blur
![image](https://github.com/Aeziren/image-filter/assets/123553708/87e61a31-29c8-49c8-9785-3b9ace992b68)

![image](https://github.com/Aeziren/image-filter/assets/123553708/827b57d4-e97a-4a83-a2b7-f07658ae6d74)















