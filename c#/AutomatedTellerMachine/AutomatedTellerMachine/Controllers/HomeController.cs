using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace AutomatedTellerMachine.Controllers
{
    public class HomeController : Controller
    {

        // Get /home/index <--- Routing
        public ActionResult Index()
        {
            return View();
        }

        // Get /home/about <--- Routing
        [ActionName("about-this-atm")]
        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.TheMessage = "Having Trouble Send us a Message";

            return View();
        }

        [HttpPost]
        public ActionResult Contact(string message)
        {
            //TODO : esnd message to HQ
            ViewBag.TheMessage = "Thanks, we got your message!";
            ViewBag.YourMessage = message;
            return View();
        }

        public ActionResult Foo()
        {
            return View("About");
        }

        public ActionResult Serial(String letterCase)
        {
            var serial = "ASPNETMVC5ATM1";
            if(letterCase == "lower")
            {
                return Content(serial.ToLower());
            }

            //return new HttpStatusCodeResult(403);
            //return Json(new { name = "serial", value = serial }, JsonRequestBehavior.AllowGet);
            return RedirectToAction("Index");
        }
    }
}