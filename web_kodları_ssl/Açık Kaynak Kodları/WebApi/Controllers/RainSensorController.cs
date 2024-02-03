using Business.Abstract;
using Business.Concrete;
using DataAccess.Concrete.EntityFramework;
using Entities.Concrete;
using Entities.Dtos;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace WebApi.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class RainSensorController : ControllerBase
    {
        private readonly IRainSensorService _rainSensorService;
        private readonly IRoofActivityService _roofActivityService;

        public RainSensorController(IRainSensorService rainSensorService, IRoofActivityService roofActivityService)
        {
            _rainSensorService = rainSensorService;
            _roofActivityService = roofActivityService;

            if (!Config.Application.ContainsKey("previousData"))
            {
                Config.Application["previousData"] = null;
            }
        }

        [HttpGet("GetRoofEndData")]
        public async Task<IActionResult> GetRoofEndData()
        {
            var value = await _roofActivityService.GetEndActivity();
            RoofActivityDto roofActivityDto = new RoofActivityDto();
            roofActivityDto.ActivityType = value.ActivityType;
            return Ok(roofActivityDto);
        }


        public static class Config
        {
            public static Dictionary<string, int?> Application = new Dictionary<string, int?>();
        }

        [HttpPost("SendData")]
        public async Task<IActionResult> RainSensorPost(RainSensoDto rainSensordto)
        {
            try
            {
                if (Config.Application["previousData"] != rainSensordto.isRain)
                {
                    Config.Application["previousData"] = rainSensordto.isRain;
                    _rainSensorService.Add(rainSensordto);
                }

                return Ok();
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
            
        }
    }
}





