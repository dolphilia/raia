var {Core, Event, GLFW, Window} = require('test');
var window = new Window("title", 800, 600);//Raia.initWindow("title", 800, 600);
var event = new Event();
var core = new Core();
var glfw = new GLFW();

var canvasWidth = 800;
var canvasHeight = 600;

function Vec3(x, y, z) {
    this.x = x;
    this.y = y;
    this.z = z;
}

Vec3.prototype.add = function (v) {
    return new Vec3(this.x + v.x, this.y + v.y, this.z + v.z);
};

Vec3.prototype.subtract = function (v) {
    return new Vec3(this.x - v.x, this.y - v.y, this.z - v.z);
};

Vec3.prototype.dot = function (v) {
    return this.x * v.x + this.y * v.y + this.z * v.z;
};

Vec3.prototype.multiply = function (scalar) {
    return new Vec3(this.x * scalar, this.y * scalar, this.z * scalar);
};

Vec3.prototype.normalize = function () {
    var length = Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z);
    return new Vec3(this.x / length, this.y / length, this.z / length);
};

function Ray(origin, direction) {
    this.origin = origin;
    this.direction = direction;
}

function Sphere(center, radius) {
    this.center = center;
    this.radius = radius;
}

Sphere.prototype.intersect = function (ray) {
    var oc = ray.origin.subtract(this.center);
    var a = ray.direction.dot(ray.direction);
    var b = 2.0 * oc.dot(ray.direction);
    var c = oc.dot(oc) - this.radius * this.radius;
    var discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return -1;
    } else {
        return (-b - Math.sqrt(discriminant)) / (2.0 * a);
    }
};

function Plane(normal, distance) {
    this.normal = normal;
    this.distance = distance;
}

Plane.prototype.intersect = function(ray) {
    var denom = this.normal.dot(ray.direction);
    if (Math.abs(denom) < 1e-6) {
        return -1;
    }
    return -(this.normal.dot(ray.origin) + this.distance) / denom;
};

function render() {
    var sphere = new Sphere(new Vec3(0, 0, -5), 1);
    var floor = new Plane(new Vec3(0, 1, 0), -1);
    var light = new Vec3(0, 5, -5);

    for (var y = 0; y < canvasHeight; y++) {
        for (var x = 0; x < canvasWidth; x++) {
            var u = 2.0 * x / canvasWidth - 1.0;
            var v = 2.0 * y / canvasHeight - 1.0;
            var ray = new Ray(new Vec3(0, 0, 0), new Vec3(u, v, -1).normalize());

            var t = sphere.intersect(ray);
            var tPlane = floor.intersect(ray);

            if (t > 0) {
                var hitPoint = ray.origin.add(ray.direction.multiply(t));
                var normal = hitPoint.subtract(sphere.center).normalize();
                var lightDirection = light.subtract(hitPoint).normalize();
                var reflectDirection = lightDirection.subtract(normal.multiply(2 * lightDirection.dot(normal))).normalize();
                var viewDirection = ray.direction.multiply(-1);
                var specularIntensity = Math.pow(Math.max(0, reflectDirection.dot(viewDirection)), 64);

                window.setCurrentColor(255 * specularIntensity, 0, 0);
                window.drawPoint(x, y);
            } else if (tPlane > 0) {
                var hitPoint = ray.origin.add(ray.direction.multiply(tPlane));
                var checkerboard = (Math.floor(hitPoint.x) + Math.floor(hitPoint.z)) % 2 === 0;
                window.setCurrentColor(checkerboard ? 255 : 0, checkerboard ? 255 : 0, checkerboard ? 255 : 0);
                window.drawPoint(x, y);
            } else {
                window.setCurrentColor(0, 0, 255);
                window.drawPoint(x, y);
            }
        }
    }
}


window.onUpdate(function () {
    render();
    window.redraw();
});

onKey(function (key, action) {
    // 何もしない
});