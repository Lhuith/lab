$(function (){
        
        var scene, camera, renderer;
        var controls, guiControls, datGUI;

        var sphereGeo, planeGeo;
        var torusLine;
        var stats;
        var sphereMaterialineBasic, sphereMaterialDashed;
        var SCREEN_WIDTH, SCREEN_HEIGHT;
        var ani = 0;

        function init() {
            //Creates empty scene object and renderers
            scene = new THREE.Scene();
            camera = new THREE.PerspectiveCamera(45, window.innerWidth / window.innerHeight, 0.1, 500);
            renderer = new THREE.WebGLRenderer({ antialias: true });

            renderer.setClearColor(0x000000);
            renderer.setSize(window.innerWidth, window.innerHeight);
            renderer.shadowMap.enabled = true;
            renderer.shadowMapSoft = true;

            //Add Controls
            controls = new THREE.OrbitControls(camera, renderer.domElement);
            controls.addEventListener("change", render);

            //Creae Sphere Materail
            sphereGeo = new THREE.SphereGeometry(30, 32, 32);
            sphereMaterialineBasic = new THREE.LineBasicMaterial({
                linewidth : 2,
                color: 0xffffff
            });
 

            sphereMaterialDashed = new THREE.LineDashedMaterial({
                color: 0xffffff,
                dashSize: 3,
                scale: 1,
                gapSize: 1,
                lineWidth:5
            });


            torusLine = new THREE.Line(geo2line(sphereGeo), sphereMaterialDashed, THREE.LinePieces);

            //Position and add objects to scene
            torusLine.position.x = 2.5;
            torusLine.position.y = 6;
            torusLine.position.z = 2.5;
            torusLine.castShadow = false;
            scene.add(torusLine);


            camera.position.x = 10;
            camera.position.y = 20;
            camera.position.z = 10;
            camera.lookAt(scene.position);


            //datGUIcontrols Object
            guiControls = new function () {
                //geo position
                this.rotationX = 0.01;
                this.rotationY = 0.01;
                this.rotationZ = 0.01;

                //Line Material
                this.material = "dashed";
                this.color = "#ffffff";
                this.scale = 1;
                this.dashSize = 0.001;
                this.gapSize = 1;
            }

            //adds controls to scene
            datGUI = new dat.GUI();
            var rotFolder = datGUI.addFolder("Rotation Options");
            var matFolder = datGUI.addFolder("Material Options");
            matFolder.open();


            rotFolder.add(guiControls, "rotationX", 0, 1);
            rotFolder.add(guiControls, "rotationY", 0, 1);
            rotFolder.add(guiControls, "rotationZ", 0, 1);


            matFolder.add(guiControls, "material", ["solid", "dashed"]).onChange(function (value)
            {
                if (guiControls.target == "solid")
                {
                    torusLine.material = sphereMaterialineBasic;
                }
                else if (guiControls.target == "sphereMaterialDashed")
                {
                    torusLine.material = sphereMaterialDashed;
                }
            });

            matFolder.addColor(guiControls, "color").onChange(function (value)
            {
                torusLine.material.color.setHex(value.replace('#', '0x'));
            });
            
            matFolder.add(guiControls, "dashSize", 0, 1).listen();

            matFolder.add(guiControls, "gapSize",0,3).step(.05).onChange(function (value) {
                torusLine.material.gapSize = value;
            });
            datGUI.close();

            $("#webgl2-container").append(renderer.domElement);    
            //stats
            stats = new Stats();
            stats.domElement.style.position = "absolute";
            stats.domElement.style.left = "0px";
            stats.domElement.style.top = "0px";
            $("#webgl2-container").append(stats.domElement);
        }

        function geo2line(geo)
        {
            var geometry = new THREE.Geometry();
            var vertices = geometry.vertices;

            for(i = 0; i < geo.faces.length; i++)
            {
                var face = geo.faces[i];

                if (face instanceof THREE.Face3)
                {
                    vertices.push(geo.vertices[face.a].clone());
                    vertices.push(geo.vertices[face.b].clone());
                    vertices.push(geo.vertices[face.b].clone());
                    vertices.push(geo.vertices[face.c].clone());
                    vertices.push(geo.vertices[face.c].clone());
                    vertices.push(geo.vertices[face.a].clone());
                }
                else if (face instanceof THREE.Face4)
                {
                    vertices.push(geo.vertices[face.a].clone());
                    vertices.push(geo.vertices[face.b].clone());
                    vertices.push(geo.vertices[face.b].clone());
                    vertices.push(geo.vertices[face.c].clone());
                    vertices.push(geo.vertices[face.c].clone());
                    vertices.push(geo.vertices[face.d].clone());
                    vertices.push(geo.vertices[face.d].clone());
                    vertices.push(geo.vertices[face.a].clone());
                }
            }

            geometry.computeLineDistances();
            return geometry;

        }
            function render() {
                torusLine.rotation.x += guiControls.rotationX;
                torusLine.rotation.y += guiControls.rotationY;
                torusLine.rotation.z += guiControls.rotationZ;

                if ((ani < 1) && (ani > 0))
                {
                    ani += 0.0001;
                    torusLine.material.dashSize = ani * 1;
                    guiControls.dashSize = ani;
                } else if (ani > 1) {
                    ani *= -1;
                    ani += 0.0001;
                    torusLine.material.dashSize = ani * -1;
                    guiControls.dashSize = ani*-1;
                } else {
                    ani += 0.0001;
                    torusLine.material.dashSize = ani * -1;
                    guiControls.dashSize = ani * -1;
                }
            }

            function animate()
            {
                console.log(ani);
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