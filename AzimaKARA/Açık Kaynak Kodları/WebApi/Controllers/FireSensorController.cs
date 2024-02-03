using Business.Abstract;
using Entities.Concrete;
using Entities.Dtos;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace WebApi.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class FireSensorController : ControllerBase
    {
        private readonly IFireSensorService _fireSensorService;
        private readonly IFireBuzzerService _fireBuzzerService;
        private readonly IFireFunService _fireFunService;

        public FireSensorController(IFireSensorService fireSensorService, IFireBuzzerService fireBuzzerService, IFireFunService fireFunService)
        {
            _fireSensorService = fireSensorService;
            _fireBuzzerService = fireBuzzerService;
            _fireFunService = fireFunService;

            if (!Config.Application.ContainsKey("previousData"))
            {
                Config.Application["previousData"] = null;
            }
        }
        public static class Config
        {
            public static Dictionary<string, int?> Application = new Dictionary<string, int?>();
        }

        [HttpPost("SendData")]
        public IActionResult RainSensorPost(FireSensorDto fireSensorDto)
        {
            try
            {
                if (Config.Application["previousData"] != fireSensorDto.isFire)
                {
                    Config.Application["previousData"] = fireSensorDto.isFire;
                    _fireSensorService.Add(fireSensorDto);

                }
                return Ok();

            }
            catch (Exception)
            {

                throw;
            }
          
        }

        [HttpGet("GetBuzzerEndData")]
        public async Task<IActionResult> FireBuzzerGet()
        {
            var values = await _fireBuzzerService.GetEndData();
            FireBuzzerDto fireBuzzerDto = new FireBuzzerDto();
            fireBuzzerDto.BuzzerActivity = values.BuzzerActivity;
            return Ok(fireBuzzerDto);
        }

        [HttpGet("GetFanEndData")]
        public async Task<IActionResult> FireFanGet()
        {
            var values = await _fireFunService.EndDataGet();
            FireFanDto fireFanDto = new FireFanDto();
            fireFanDto.Activity = values.Activity;
            return Ok(fireFanDto);
        }
    }
}
