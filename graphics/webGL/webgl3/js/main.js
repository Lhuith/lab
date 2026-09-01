$(function (){
        
        var scene, camera, renderer;
        var controls, guiControls, datGUI;

        var genGeo, sphereGeo, boxGeo, cylinderGeo, dodecahedronGeo, icosahedronGeo, octaHedronGeo, planeGeo, ringGeo, tetraHedronGeo, torusGeo, torusknotGeo;
        var lineMaterial;
        var torusKnot, plane, sphere, shape, mesh;
        var stats;
        var SCREEN_WIDTH, SCREEN_HEIGHT;
        var materials;

        function init() {
            //Creates empty scene object and renderers
            scene = new THREE.Scene();
            camera = new THREE.PerspectiveCamera(45, window.innerWidth / window.innerHeight, 0.1, 500);
            renderer = new THREE.WebGLRenderer({ antialias: true });

            renderer.setClearColor(0xffffff);
            renderer.setSize(window.innerWidth, window.innerHeight);
            renderer.shadowMap.enabled = true;
            renderer.shadowMapSoft = true;

            //Add Controls
            controls = new THREE.OrbitControls(camera, renderer.domElement);
            controls.addEventListener("change", render);


            //datGUIcontrols Object
            guiControls = new function () {
                //geo position
                this.rotationX = 0.01;
                this.rotationY = 0.01;
                this.rotationZ = 0.01;

                //Material
                this.color = "#000000";
                this.form = 0;
                this.wireframe = true;
                //Mesh or Lins
                this.lineshape = true;
            }

            //Create Geometries
            genGeometryShape =
                [
            boxGeo = new THREE.BoxGeometry(6, 6, 6, 6),
            cylinderGeo = new THREE.CylinderGeometry(6,6,6,6),
            dodecahedronGeo = new THREE.DodecahedronGeometry(6),
            icosahedronGeo = new THREE.IcosahedronGeometry(6),
            octaHedronGeo = new THREE.OctahedronGeometry(6),
            sphereGeo = new THREE.SphereGeometry(6, 32, 32),
            ringGeo = new THREE.RingGeometry(1,5,32),
            torusGeo = new THREE.TorusGeometry(3,3,32,32),
            torusknotGeo = new THREE.TorusKnotGeometry(3,3,32,32)
            ];

            //Create Geometries
            genGeometryMesh =
                [
            boxGeo = new THREE.BoxGeometry(6, 6, 6, 6),
            cylinderGeo = new THREE.CylinderGeometry(6, 6, 6, 6),
            dodecahedronGeo = new THREE.DodecahedronGeometry(6),
            icosahedronGeo = new THREE.IcosahedronGeometry(6),
            octaHedronGeo = new THREE.OctahedronGeometry(6),
            sphereGeo = new THREE.SphereGeometry(6, 32, 32),
            ringGeo = new THREE.RingGeometry(1, 5, 32),
            torusGeo = new THREE.TorusGeometry(3, 3, 32, 32),
            torusknotGeo = new THREE.TorusKnotGeometry(3, 3, 32, 32)
            ];


            //Material and !!!!!!!!!INTITIAL!!!!!!!!!!! object creation
            materials =
                [
                linemateral = new THREE.LineBasicMaterial({ color: guiControls.color }),
                meshBasicMaterial = new THREE.MeshBasicMaterial({ color: guiControls.color, wireframe: true , side: THREE.DoubleSide })
            ];

            shape = new THREE.Line(genGeometryShape[0], materials[0]);
            mesh = new THREE.Mesh(genGeometryMesh[0], materials[1]);

            //Position and add objects to scene
            shape.position.x = 2.5;
            shape.position.y = 6;
            shape.position.z = 2.5;
            shape.castShadow = true;
            scene.add(shape);

            mesh.position.x = 2.5;
            mesh.position.y = 6;
            mesh.position.z = 2.5;
            mesh.castShadow = true;


            camera.position.x = 10;
            camera.position.y = 20;
            camera.position.z = 10;
            camera.lookAt(scene.position);

            //adds controls to scene
            datGUI = new dat.GUI();
            var rotFolder = datGUI.addFolder("Rotation Options");
            var shapeFolder = datGUI.addFolder("Form Options")
            var matFolder = datGUI.addFolder("Material Options");

            matFolder.open();


            rotFolder.add(guiControls, "rotationX", 0, 1);
            rotFolder.add(guiControls, "rotationY", 0, 1);
            rotFolder.add(guiControls, "rotationZ", 0, 1);

            matFolder.addColor(guiControls, "color").onChange(function (value) {
                shape.material.color.setHex(value);
                mesh.material.color.setHex(value);
            });

            matFolder.add(guiControls, "lineshape").name("Line Shape").onChange(function(value)
            {
                if (value == true)
                {
                    console.log(shape);
                    scene.remove(mesh);
                    scene.add(shape = new THREE.Line(genGeometryShape[guiControls.form], materials[0]));
                }
                else
                {
                    console.log(mesh);
                    scene.remove(shape);
                    scene.add(mesh = new THREE.Mesh(genGeometryMesh[guiControls.form], materials[1]));
                }
            });

            matFolder.add(guiControls, "wireframe").name("wireframe").onChange(function (value)
            {
                if (mesh.material.wireframe == false)
                {
                    mesh.material.wireframe = true;
                }
                else
                {
                    mesh.material.wireframe = false; 
                }
            });

            shapeFolder.add(guiControls, "form", { "Box": 0, "Cylinder": 1, "Dodecahedron": 2, "Icosahedron": 3, "Octahedron": 4, "Sphere": 5, "Ring": 6, "Torus": 7,"TorusKnot": 8 }).onChange(function (value)
            {
                if (value == 0 && guiControls.lineshape == true)
                {
                    scene.remove(shape);
                    scene.remove(mesh);
                    shape = new THREE.Line(genGeometryShape[0], materials[0]);
                    scene.add(shape);
                }
                else if(value == 0 && guiControls.lineshape == false)
                {
                    scene.remove(shape);
                    scene.remove(mesh);
                    mesh = new THREE.Mesh(genGeometryMesh[0], materials[1]);
                    scene.add(mesh);
                }
                else if (value == 1 && guiControls.lineshape == true)
                {
                    scene.remove(shape);
                    scene.remove(mesh);
                    shape = new THREE.Line(genGeometryShape[1], materials[0]);
                    scene.add(shape);
                }
                else if (value == 1 && guiControls.lineshape == false)
                {
                    scene.remove(shape);
                    scene.remove(mesh);
                    mesh = new THREE.Mesh(genGeometryMesh[1], materials[1]);
                    scene.add(mesh);
                } else if (value == 2 && guiControls.lineshape == true)
                {
                    scene.remove(shape);
                    scene.remove(mesh);
                    shape = new THREE.Line(genGeometryShape[2], materials[0]);
                    scene.add(shape);
                }
                else if (value == 2 && guiControls.lineshape == false)
                {
                    scene.remove(shape);
                    scene.remove(mesh);
                    mesh = new THREE.Mesh(genGeometryMesh[2], materials[1]);
                    scene.add(mesh);
                }
                else if (value == 3 && guiControls.lineshape == true)
                {
                    scene.remove(shape);
                    scene.remove(mesh);
                    shape = new THREE.Line(genGeometryShape[3], materials[0]);
                    scene.add(shape);
                }
                else if (value == 3 && guiControls.lineshape == false)
                {
                    scene.remove(shape);
                    scene.remove(mesh);
                    mesh = new THREE.Mesh(genGeometryMesh[3], materials[1]);
                    scene.add(mesh);
                } else if (value == 4 && guiControls.lineshape == true)
                {
                    scene.remove(shape);
                    scene.remove(mesh);
                    shape = new THREE.Line(genGeometryShape[4], materials[0]);
                    scene.add(shape);
                }
                else if (value == 4 && guiControls.lineshape == false)
                {
                    scene.remove(shape);
                    scene.remove(mesh);
                    mesh = new THREE.Mesh(genGeometryMesh[4], materials[1]);
                    scene.add(mesh);
                }
                else if (value == 5 && guiControls.lineshape == true)
                {
                    scene.remove(shape);
                    scene.remove(mesh);
                    shape = new THREE.Line(genGeometryShape[5], materials[0]);
                    scene.add(shape);
                }
                else if (value == 5 && guiControls.lineshape == false)
                {
                    scene.remove(shape);
                    scene.remove(mesh);
                    mesh = new THREE.Mesh(genGeometryMesh[5], materials[1]);
                    scene.add(mesh);
                }
                else if (value == 6 && guiControls.lineshape == true)
                {
                    scene.remove(shape);
                    scene.remove(mesh);
                    shape = new THREE.Line(genGeometryShape[6], materials[0]);
                    scene.add(shape);
                }
                else if (value == 6 && guiControls.lineshape == false)
                {
                    scene.remove(shape);
                    scene.remove(mesh);
                    mesh = new THREE.Mesh(genGeometryMesh[6], materials[1]);
                    scene.add(mesh);
                }
                else if (value == 7 && guiControls.lineshape == true)
                {
                    scene.remove(shape);
                    scene.remove(mesh);
                    shape = new THREE.Line(genGeometryShape[7], materials[0]);
                    scene.add(shape);
                }
                else if (value == 7 && guiControls.lineshape == false)
                {
                    scene.remove(shape);
                    scene.remove(mesh);
                    mesh = new THREE.Mesh(genGeometryMesh[7], materials[1]);
                    scene.add(mesh);
                }
                else if (value == 8 && guiControls.lineshape == true)
                {
                    scene.remove(shape);
                    scene.remove(mesh);
                    shape = new THREE.Line(genGeometryShape[8], materials[0]);
                    scene.add(shape);
                }
                else if (value == 8 && guiControls.lineshape == false)
                {
                    scene.remove(shape);
                    scene.remove(mesh);
                    mesh = new THREE.Mesh(genGeometryMesh[8], materials[1]);
                    scene.add(mesh);
                }
            });

        
 
            datGUI.close();
      

            $("#webgl3-container").append(renderer.domElement);
            //stats
            stats = new Stats();
            stats.domElement.style.position = "absolute";
            stats.domElement.style.left = "0px";
            stats.domElement.style.top = "0px";
            $("#webgl3-container").append(stats.domElement);
        }


            function render() {
                shape.rotation.x += guiControls.rotationX;
                shape.rotation.y += guiControls.rotationY;
                shape.rotation.z += guiControls.rotationZ;

                mesh.rotation.x += guiControls.rotationX;
                mesh.rotation.y += guiControls.rotationY;
                mesh.rotation.z += guiControls.rotationZ;
            }

            function animate()
            {
                requestAnimationFrame(animate);
                render();
                stats.update();  
                renderer.render(scene, camera);
            }

            $(window).resize(function(){
                SCREEN_WIDTH = window.innerWidth;
                SCREEN_HEIGHT = window.innerHeight;

                camera.aspect = SCREEN_WIDTH/SCREEN_HEIGHT;
                camera.updateProjectionMatrix();

                renderer.setSize(SCREEN_WIDTH, SCREEN_HEIGHT);
            });

            init();
            animate();
        
});