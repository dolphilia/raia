var {Window, Surface} = require('raia');
var window = new Window("title", 800, 600);

window.setTitle("サンプル");

var canvasWidth = 800;
var canvasHeight = 600;

var camera = {
    position: { x: 5, y: -5, z: 3 },
    target: { x: 0, y: 0, z: 0 },
};

var cube = {
    vertices: [
        { x: -1, y: -1, z: -1 },
        { x: 1, y: -1, z: -1 },
        { x: -1, y: 1, z: -1 },
        { x: 1, y: 1, z: -1 },
        { x: -1, y: -1, z: 1 },
        { x: 1, y: -1, z: 1 },
        { x: -1, y: 1, z: 1 },
        { x: 1, y: 1, z: 1 },
    ],
};

for(var i = 0; i < cube.vertices.length; i++) {
    cube.vertices[i].z = cube.vertices[i].z;
    cube.vertices[i].y = cube.vertices[i].y;
}

function drawCubeWireframe(vertices) {
    var edges = [
        [0, 1], [1, 3], [3, 2], [2, 0], // front face
        [4, 5], [5, 7], [7, 6], [6, 4], // back face
        [0, 4], [1, 5], [2, 6], [3, 7], // connecting edges
    ];

    edges.forEach(function (edge) {
        var start = vertices[edge[0]];
        var end = vertices[edge[1]];
        window.drawLine3D(start.x, start.y, start.z, end.x, end.y, end.z);
    });
}

window.init3D(800, 600);
window.setCamera(1400, 1200, 1000,  0, 0, 0);
window.setCurrentColor(255,255,255,255)
window.drawPoint3D(0,0,0);
window.drawLine3D(0,0,0, 0, 100, 200);

var angle = 0;

window.onUpdate(() => {
    window.setCurrentColor(255,255,255,255);
    window.drawFilledRect(0,0,800,600);
    window.setCurrentColor(64,0,64,255);
    angle += 0.002;
    var radius = Math.sqrt(Math.pow(camera.position.x, 2) + Math.pow(camera.position.y, 2));
    var x = radius * Math.cos(angle);
    var y = radius * Math.sin(angle);
    window.setCamera(x, y, camera.position.z, 0, 0, 0);
    drawCubeWireframe(cube.vertices);
    window.redraw();
});