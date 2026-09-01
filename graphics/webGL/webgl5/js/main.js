$(function (){

        var scene, camera, renderer;
        var controls, guiControls, datGUI;
        var axis, grid, color;
        var cubeGeo, torGeo, textGeo, planeGeo;
        var cubeMat, torMat, textMat, planeMat;
        var cube, torusKnot, text, plane;
        var spotLight, hemiLight, pointLightHelper, hemiLightHelper;
        var stats;
        var SCREEN_WIDTH, SCREEN_HEIGHT;

		var lightArray;
		var ambient = 0;
		var area = 0;
		var directional = 0;
		var hemisphere = 0;
		var point = 0;
		var spot = 0;
		var light;
		
        function init() {
            //Creates empty scene object and renderers
            scene = new THREE.Scene();
            camera = new THREE.PerspectiveCamera(45, window.innerWidth / window.innerHeight, 0.1, 500);
            renderer = new THREE.WebGLRenderer({ antialias: true });

            renderer.setClearColor(0xdddddd);
            renderer.setSize(window.innerWidth, window.innerHeight);
            renderer.shadowMap.enabled = true;
            renderer.shadowMapSoft = true;
            
			//Add Controls
            controls = new THREE.OrbitControls(camera, renderer.domElement);
            controls.addEventListener("change", render);

            //Adds helpers
            var axis = new THREE.AxisHelper(10);
            scene.add(axis);

            grid = new THREE.GridHelper(50, 5);
            color = new THREE.Color("rgb(255,0,0)");
            grid.setColors(color, 0x000000);

            scene.add(grid);

            //Create Cube
            cubeGeo = new THREE.CubeGeometry(5, 5, 5);
            cubeMat  = new THREE.MeshLambertMaterial({ color: 0xff330 });
            cube = new THREE.Mesh(cubeGeo, cubeMat);
       

            //Creae torusKnot
            torGeo = new THREE.TorusKnotGeometry(3, 1, 64, 64);
            torMat = new THREE.MeshPhongMaterial({ color: 0xffff00 });
            torusKnot = new THREE.Mesh(torGeo, torMat);

            //Create Text
            textGeo = new THREE.TextGeometry('ANUS', { size: 2, height: 1 });
            textMat = new THREE.MeshPhongMaterial({ color: 0xff9000 });
            text = new THREE.Mesh(textGeo, textMat);

            //Create Plan
            planeGeo = new THREE.PlaneGeometry(100, 100, 100);
            planeMat = new THREE.MeshLambertMaterial({ color: 0xffffff });
            plane = new THREE.Mesh(planeGeo, planeMat);

            //Position and add objects to scene
            plane.rotation.x = -.5 * Math.PI;
            plane.receiveShadow = true;
            scene.add(plane);

            cube.position.x = 2.5;
            cube.position.y = 4;
            cube.position.z = 2.5;
            cube.castShadow = true;
            scene.add(cube);

            torusKnot.position.x = -15;
            torusKnot.position.y = 6;
            torusKnot.position.z = 2.5;
            torusKnot.castShadow = true;
            scene.add(torusKnot);

            ////Create Text2
            //var text2 = new THREE.Line(textGeo, textMat)
            //text2.position.x = 15;
            //text2.position.y = 12;
            //text2.position.z = 2.5
            //scene.add(text2);

            text.position.x = 15;
            text.position.y = 6;
            text.position.z = 2.5;
            text.castShadow = true;
            scene.add(text);

            camera.position.x = 40;
            camera.position.y = 40;
            camera.position.z = 40;
            camera.lookAt(scene.position);
            lightArray = 
            [
            new THREE.AmbientLight(),
            new THREE.DirectionalLight(),
            new THREE.PointLight (),
            new THREE.SpotLight()
            ];
            //datGUIcontrols Object
            guiControls = new function () {
                this.rotationX = 0.01;
                this.rotationY = 0.01;
                this.rotationZ = 0.01;

                //Adds Lights Controls
                this.lightSelector = 0;

                this.addLight = function () {
                    addLight();
                };
                this.deleteLight = function () {
                    deleteLight();
                };

                this.ambColor = 0xdddddd;

                //Directional Light values
                this.dirColor = 0xffffff;
                this.lightDX = 20;
                this.lightDY = 35;
                this.lightDZ = 40;
                this.intensityD = 1;
                this.shadowCameraNearD = 1;
                this.shadowCameraFarD = 75;
                this.shadowLeft = -5;
                this.shadowRight = 5;
                this.shadowTop = 5;
                this.shadowBottom = -5;
                this.shadowCameraVisibleD = false;
                this.shadowMapWidthD = 2056;
                this.shadowMapHeightD = 2056;
                this.shadowBiasD = 0.00;
                this.shadowDarknessD = 0.5;
                this.targetD = cube;

                //hemisphere light parametres
                this.skyColor = 0x140404;
                this.groundColorH = 0x140404;
                this.inensityH = 1;

                //PointLight values
                this.colorP = 0x00ff39;
                this.intensityP = 1;
                this.distanceP = 0; 
                this.lightXP = 20;
                this.lightYP = 35;
                this.lightZP = 40; 


                //SpotLight Values
                this.lightX = 20;
                this.lightY = 35;
                this.lightZ = 40;
                this.intensity = 1;
                this.distance = 0; 
                this.angle = 1.570;
                this.exponent = 0;
                this.shadowCameraNear = 10;
                this.shadowCameraFar = 100;
                this.shadowCameraFov = 50;
                this.shadowCameraVisible = true;
                this.shadowMapWidth = 1028;
                this.shadowMapHeight = 1028;
                this.shadowBias = 0;
                this.shadowDarkness = 0.5;
                this.target = cube;
            }

            //Ambient light parametres
            lightArray[0].color.setHex(guiControls.ambColor);
            console.log(scene);

            //directional Light parametres
            lightArray[1].color.setHex(guiControls.ambColor);
     
            lightArray[1].castShadow = true;
            lightArray[1].position.set(20, 35, 40);
            lightArray[1].intensity = guiControls.intensityD;
            lightArray[1].distance = guiControls.distanceD;
            lightArray[1].angle = guiControls.angleD;
            lightArray[1].exponent = guiControls.exponentD;
            lightArray[1].shadow.camera.near = guiControls.shadowCameraNearD;
            lightArray[1].shadow.camera.far = guiControls.shadowCameraFarD;
            lightArray[1].shadow.camera.fov = guiControls.shadowCameraFovD;

            lightArray[1].shadow.camera.left = guiControls.shadowLeft;
            lightArray[1].shadow.camera.right = guiControls.shadowRight;
            lightArray[1].shadow.camera.top = guiControls.shadowTop;
            lightArray[1].shadow.camera.bottom = guiControls.shadowBottom;

            lightArray[1].shadow.camera.visible = guiControls.shadowCameraVisibleD;
            lightArray[1].shadow.bias = guiControls.shadowBiasD;
            lightArray[1].shadow.darkness = guiControls.shadowDarknessD;

           
            lightArray[1].shadow.darkness = guiControls.shadowDarknessD;

            //Point Light parametres
            lightArray[2].color.setHex(guiControls.colorP);
            lightArray[2].intensity = guiControls.intensityP;
            lightArray[2].distance = guiControls.distanceP;
            lightArray[2].position.set(guiControls.lightXP, guiControls.lightYP, guiControls.lightZP);

            //Adds Spot light with start parametres
            lightArray[3].castShadow = true;
            lightArray[3].position.set(20, 35, 40);
            lightArray[3].intensity = guiControls.intensity;
            lightArray[3].shadow.camera.near = guiControls.shadowCameraNear;
            lightArray[3].shadow.camera.far = guiControls.shadowCameraFar;
            lightArray[3].shadow.camera.visible = guiControls.shadowCameraVisible;
            lightArray[3].shadow.bias = guiControls.shadowBias;
            lightArray[3].shadow.darkness = guiControls.shadowDarkness;

            //var test = new THREE.CameraHelper(spotLight);
           // test.camera.visible = true;
                

            //Light selection controls
            datGUI = new dat.GUI();

            datGUI.add(guiControls, "lightSelector", { "Ambient": 0, "Directional": 1, "Point": 2, "Spot": 3, "Hemisphere": 4 }).name("light Selection");
            datGUI.add(guiControls, "addLight").name("Add a Light");
            datGUI.add(guiControls, "deleteLight").name("Delete a Light");


            //Cube Controls
            var geoFolder = datGUI.addFolder("Cube");
            geoFolder.add(guiControls, "rotationX", 0, 1);
            geoFolder.add(guiControls, "rotationY", 0, 1);
            geoFolder.add(guiControls, "rotationZ", 0, 1);

            //Ambient Controls
            var ambFolder = datGUI.addFolder("Ambient Light");
            ambFolder.addColor(guiControls, "ambColor").onChange(function(value){
                lightArray[0].color.setHex(value);
            });
            //////////////

            //Directional Controls
            //////////////////////////////////////////////////////////////////////////////////
            var directFolder = datGUI.addFolder("Directional Light");
            directFolder.addColor(guiControls, "dirColor").onChange(function(value){
                lightArray[1].color.setHex(value);
            });
            directFolder.add(guiControls, "lightDX", -60, 180);
            directFolder.add(guiControls, "lightDY", 0, 180);
            directFolder.add(guiControls, "lightDZ", -60, 180);
            directFolder.add(guiControls, "target", ["cube", "torusKnot", "text"]).onChange(function() {
                if(guiControls.target == "cube")
                {
                    lightArray[1].target = cube;
                }
                else if(guiControls.target == "torusKnot")
                {
                    lightArray[1].target = torusKnot;
                }
                else if(guiControls.target == "text")
                {
                    lightArray[1].target = text;
                }
            });

            directFolder.add(guiControls, "intensityD", 0.01, 5).onChange(function(value){
                lightArray[1].intensity = value;
            });
            directFolder.add(guiControls, "shadowCameraNearD", 0, 100).name("Near").onChange(function (value) {
                lightArray[1].shadow.camera.near = value;
                lightArray[1].shadow.camera.updateProjectionMatrix();
            });

            directFolder.add(guiControls, "shadowLeft", -30, 30).name("Left").onChange(function (value) {
                lightArray[1].shadow.camera.left = value;
                lightArray[1].shadow.camera.updateProjectionMatrix();
            });
            directFolder.add(guiControls, "shadowRight", -30, 30).name("Right").onChange(function (value) {
                lightArray[1].shadow.camera.right = value;
                lightArray[1].shadow.camera.updateProjectionMatrix();
            });
            directFolder.add(guiControls, "shadowTop", -30, 30).name("Top").onChange(function (value) {
                lightArray[1].shadow.camera.top = value;
                lightArray[1].shadow.camera.updateProjectionMatrix();
            });
            directFolder.add(guiControls, "shadowBottom", -30, 30).name("Bottom").onChange(function (value) {
                lightArray[1].shadow.camera.bottom = value;
                lightArray[1].shadow.camera.updateProjectionMatrix();
            });

            directFolder.add(guiControls, "shadowCameraFarD", 0, 5000).name("Far").onChange(function (value) {
                lightArray[1].shadow.camera.far = value;
                lightArray[1].shadow.camera.updateProjectionMatrix();
            });
            directFolder.add(guiControls, "shadowCameraVisibleD").onChange(function(value){
                lightArray[1].shadow.camera.visible = value;
                lightArray[1].shadow.camera.updateProjectionMatrix();
            });
            directFolder.add(guiControls, "shadowBiasD", 0, 1).onChange(function(value){
                lightArray[1].shadow.bias = value;
                lightArray[1].shadow.camera.updateProjectionMatrix();
            });
            datGUI.add(guiControls, "shadowDarknessD", 0, 1).onChange(function(value){
                lightArray[1].shadow.darkness = value;
                lightArray[1].shadow.camera.updateProjectionMatrix();
            });

            /////////////////////////////////////////////////////////////////////////////////////////////////
           
            //Hemisphere Controls
            var hemiFolder = datGUI.addFolder("Hemisphere Light");

            hemiFolder.addColor(guiControls, "groundColorH").onChange(function (value) {
                if(hemisphere == 1)
                hemiLight.groundColor.setHex(value);
            });
            hemiFolder.addColor(guiControls, "skyColor").onChange(function (value) {
                if (hemisphere == 1)
                hemiLight.color.setHex(value);
            });
            
            directFolder.add(guiControls, "intensityD", 0.01, 5).onChange(function (value) {
                if (hemisphere == 1)
                hemiLight.intensity = value;
            });

            //Point Light Controls
            var pointFolder = datGUI.addFolder("Point Light");
            pointFolder.addColor(guiControls, "colorP").onChange(function(value){
                lightArray[2].color.setHex(value);
            });
            pointFolder.add(guiControls, "intensityP", 0, 5);
            pointFolder.add(guiControls, "distanceP", 0, 50);
            pointFolder.add(guiControls, "lightXP", -60, 180);
            pointFolder.add(guiControls, "lightYP", 0, 180);
            pointFolder.add(guiControls, "lightZP", -60, 180);


            /////////////////////////////////////////////////////////////


            //SpotL Light Controls
            var spotFolder = datGUI.addFolder("Spot Light");
            spotFolder.add(guiControls, "lightX", -60, 180);
            spotFolder.add(guiControls, "lightY", 0, 180);
            spotFolder.add(guiControls, "lightZ", -60, 180);

            spotFolder.add(guiControls, "target", ["cube", "torusKnot", "text"]).onChange(function() {
                if(guiControls.target == "cube")
                {
                    lightArray[3].target = cube;
                }
                else if(guiControls.target == "torusKnot")
                {
                    lightArray[3].target = torusKnot;
                }
                else if(guiControls.target == "text")
                {
                    lightArray[3].target = text;
                }
            });

            spotFolder.add(guiControls, "intensity", 0.01, 5).onChange(function(value){
                lightArray[3].intensity = value;
            });

            spotFolder.add(guiControls, "distance", 0, 1000).onChange(function(value){
                lightArray[3].distance = value;
            });
            spotFolder.add(guiControls, "angle", 0.001, 1.570).onChange(function(value){
                lightArray[3].angle = value;
            });
            spotFolder.add(guiControls, "exponent", 0, 50).onChange(function(value){
                lightArray[3].exponent = value;
            });
            spotFolder.add(guiControls, "shadowCameraNear", 0, 100).name("Near").onChange(function (value) {
                lightArray[3].shadow.camera.near = value;
                lightArray[3].shadow.camera.updateProjectionMatrix();
            });
            spotFolder.add(guiControls, "shadowCameraFar", 0, 5000).name("Far").onChange(function (value) {
                lightArray[3].shadow.camera.far = value;
                lightArray[3].shadow.camera.updateProjectionMatrix();
            });

            spotFolder.add(guiControls, "shadowCameraFov", 1, 180).name("Fov").onChange(function (value) {
                lightArray[3].shadow.camera.fov = value;
                lightArray[3].shadow.camera.updateProjectionMatrix();
            });

            spotFolder.add(guiControls, "shadowCameraVisible").onChange(function(value){
                lightArray[3].shadow.camera.visible = value;
                lightArray[3].shadow.camera.updateProjectionMatrix();
            });
            spotFolder.add(guiControls, "shadowBias", 0, 1).onChange(function(value){
                lightArray[3].shadow.bias = value;
                lightArray[3].shadow.camera.updateProjectionMatrix();
            });
            spotFolder.add(guiControls, "shadowDarkness", 0, 1).onChange(function(value){
                lightArray[3].shadow.darkness = value;
                lightArray[3].shadow.camera.updateProjectionMatrix();
            });
            spotFolder.close();


            $("#webGL-container").append(renderer.domElement);
            
            //stats
            stats = new Stats();
            stats.domElement.style.position = "absolute";
            stats.domElement.style.left = "0px";
            stats.domElement.style.top = "0px";
            $("#webGL-container").append(stats.domElement);
        }

        function addLight()
        {
            if(guiControls.lightSelector == 0 && ambient == 0)
            {
                scene.add(lightArray[guiControls.lightSelector]);
                ambient = 1;
            }
            else if(guiControls.lightSelector == 1 && directional == 0)
            {
                scene.add(lightArray[guiControls.lightSelector]);
                directional = 1;
            }
            else if(guiControls.lightSelector == 2 && point == 0)
            {
                scene.add(lightArray[guiControls.lightSelector]);
                pointLightHelper = new THREE.PointLightHelper(lightArray[guiControls.lightSelector], 1);
                scene.add(pointLightHelper);
                point = 1;
            }
            else if(guiControls.lightSelector == 3 && spot == 0)
            {
                scene.add(lightArray[guiControls.lightSelector]);
                spot = 1;
            }
            else if(guiControls.lightSelector == 4 && hemisphere == 0)
            {
                hemiLight = new THREE.HemisphereLight(0x140404, 0x140404, 3);
                hemiLight.position.set(0,10,0);
                hemiLightHelper = new THREE.HemisphereLightHelper(hemiLight, 2);
                scene.add(hemiLight);
                hemisphere = 1;
            }
        }

        function deleteLight()
        {
            if(guiControls.lightSelector == 0 && ambient == 1)
            {
                scene.remove(lightArray[guiControls.lightSelector]);
                ambient = 0;
            }
            else if(guiControls.lightSelector == 1 && directional == 1)
            {
                scene.remove(lightArray[guiControls.lightSelector]);
                directional = 0;
            }
            else if(guiControls.lightSelector == 2 && point == 1)
            {
                scene.remove(lightArray[guiControls.lightSelector]);
                scene.remove(pointLightHelper);
                point = 0;
            }
            else if(guiControls.lightSelector == 3 && spot == 1)
            {
                scene.remove(lightArray[guiControls.lightSelector]);
                spot = 0;
            }
            else if(guiControls.lightSelector == 4 && hemisphere == 1)
            {
                scene.remove(hemiLight);
                scene.remove(hemiLightHelper);
                hemisphere = 0;
            }
        }

        function render() 
        {
                cube.rotation.x += guiControls.rotationX;
                cube.rotation.y += guiControls.rotationY;
                cube.rotation.z += guiControls.rotationZ;
            //necessary to make lights function
                cubeMat.needsUpdate = true;
                torMat.needsUpdate = true;
                planeMat.needsUpdate = true;
                textMat.needsUpdate = true;

                lightArray[1].position.x = guiControls.lightDX;
                lightArray[1].position.y = guiControls.lightDY;
                lightArray[1].position.z = guiControls.lightDZ;
            
                lightArray[2].position.x = guiControls.lightXP;
                lightArray[2].position.y = guiControls.lightYP;
                lightArray[2].position.z = guiControls.lightZP; 

                lightArray[3].position.x = guiControls.lightX;
                lightArray[3].position.y = guiControls.lightY;
                lightArray[3].position.z = guiControls.lightZ; 
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