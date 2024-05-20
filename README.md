# MochaOpenGL

A simplistic OpenGL viewport to load a 3D model, adjust the material, place lights around, and that's basically it.

---

<br /><br /><br />

# Checklist
Just some text to organise my thoughts and write down what the end result needs to accomplish.

<br />

## GUI
The application should have a simple GUI so you can play around with all its features.
- Outliner for showing/selecting meshes in the scene
- Outliner for showing/selecting materials
- Outliner for showing/selecting lights
- Import/Add model button
- Material GUI to adjust all material properties

<br />

## Viewport
The viewport should show everything that is rendered, but also display some sprites to show the position of a light point for example.

<br />

## Lights
Eventually, lights should be added through the GUI and be positioned through XYZ coordinates.

<br />

## Material
The material should contain properties to be used by the shader. These properties should be exposed to a GUI. Every object has one material.

Properties:
- Adjustable Texture Tiling for U and V
- Adjustable wrap mode
- Base colour value & base colour texture, using the alpha for transparency
- Normal texture
- Specular Intensity & Shininess values (only used by phong shader)
- Metallic & roughness values (only used by "PBR" shader)
- Emission value & texture

<br />
