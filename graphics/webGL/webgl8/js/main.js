$(function (){

        var scene, camera, renderer;
        var controls, guiControls, datGUI;
        var axis, grid, color;
        var cube, torusKnot, text, plane;
        var spotLight;
        var stats;
        var SCREEN_WIDTH, SCREEN_HEIGHT;
        var loader, model;

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


            camera.position.x = 40;
            camera.position.y = 40;
            camera.position.z = 40;
            camera.lookAt(scene.position);

            //datGUIcontrols Object
            guiControls = new function () {
                this.rotationX = 0.01;
                this.rotationY = 0.01;
                this.rotationZ = 0.01;

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
    
            }

            hemi = new THREE.HemisphereLight(0xbbbbbb, 0x0099FF);
            scene.add(hemi);
            //Adds Spot light with start parametres
            spotLight = new THREE.SpotLight(0xffffff);
            spotLight.castShadow = true;
            spotLight.position.set(20, 35, 40);
            spotLight.intensity = guiControls.intensity;
            spotLight.distance = guiControls.distance;
            spotLight.angle = guiControls.angle;
            spotLight.exponent = guiControls.exponent;
            spotLight.shadow.camera.near = guiControls.shadowCameraNear;
            spotLight.shadow.camera.far = guiControls.shadowCameraFar;
            spotLight.shadow.camera.fov = guiControls.shadowCameraFov;
            spotLight.shadow.camera.visible = guiControls.shadowCameraVisible;
            spotLight.shadow.bias = guiControls.shadowBias;
            spotLight.shadow.darkness = guiControls.shadowDarkness;
            scene.add(spotLight);

            loader = new THREE.JSONLoader();
            loader.load("./models/webGL_Bench.json", addModel);

            //var test = new THREE.CameraHelper(spotLight);
           // test.camera.visible = true;
     

            //adds controls to scene
            datGUI = new dat.GUI();
            datGUI.add(guiControls, "rotationX", 0, 1);
            datGUI.add(guiControls, "rotationY", 0, 1);
            datGUI.add(guiControls, "rotationZ", 0, 1);

            datGUI.add(guiControls, "lightX", -60, 180);
            datGUI.add(guiControls, "lightY", 0, 180);
            datGUI.add(guiControls, "lightZ", -60, 180);



            datGUI.add(guiControls, "intensity", 0.01, 5).onChange(function(value){
                spotLight.intensity = value;
            });

            datGUI.add(guiControls, "distance", 0, 1000).onChange(function(value){
                spotLight.distance = value;
            });
            datGUI.add(guiControls, "angle", 0.001, 1.570).onChange(function(value){
                spotLight.angle = value;
            });
            datGUI.add(guiControls, "exponent", 0, 50).onChange(function(value){
                spotLight.exponent = value;
            });
            datGUI.add(guiControls, "shadowCameraNear", 0, 100).name("Near").onChange(function (value) {
                spotLight.shadow.camera.near = value;
                spotLight.shadow.camera.updateProjectionMatrix();
            });
            datGUI.add(guiControls, "shadowCameraFar", 0, 5000).name("Far").onChange(function (value) {
                spotLight.shadow.camera.far = value;
                spotLight.shadow.camera.updateProjectionMatrix();
            });

            datGUI.add(guiControls, "shadowCameraFov", 1, 180).name("Fov").onChange(function (value) {
                spotLight.shadow.camera.fov = value;
                spotLight.shadow.camera.updateProjectionMatrix();
            });

            datGUI.add(guiControls, "shadowCameraVisible").onChange(function(value){
                spotLight.shadow.camera.visible = value;
                spotLight.shadow.camera.updateProjectionMatrix();
            });
            datGUI.add(guiControls, "shadowBias", 0, 1).onChange(function(value){
                spotLight.shadow.bias = value;
                spotLight.shadow.camera.updateProjectionMatrix();
            });
            datGUI.add(guiControls, "shadowDarkness", 0, 1).onChange(function(value){
                spotLight.shadow.darkness = value;
                spotLight.shadow.camera.updateProjectionMatrix();
            });
           
            $("#webgl8-container").append(renderer.domElement);
            
            //stats
            stats = new Stats();
            stats.domElement.style.position = "absolute";
            stats.domElement.style.left = "0px";
            stats.domElement.style.top = "0px";
            $("#webgl8-container").append(stats.domElement);



        }

        function addModel(geometry, materials)
            {
                var material = new THREE.MeshFaceMaterial(materials);
                model = new THREE.Mesh(geometry, material);
                model.scale.set(5,5,5);
                model.position.set(0, 0, 0);
                scene.add(model);
            }
            function render() {
      
                spotLight.position.x = guiControls.lightX;
                spotLight.position.y = guiControls.lightY;
                spotLight.position.z = guiControls.lightZ;           
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