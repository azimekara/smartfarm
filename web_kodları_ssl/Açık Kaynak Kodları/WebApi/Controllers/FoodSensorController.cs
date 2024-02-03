using Business.Abstract;
using Entities.Dtos;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace WebApi.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class FoodSensorController : ControllerBase
    {
        public readonly IFoodSensorService _foodSensorService;
        public readonly IFoodMachineService _foodMachineService;

        public FoodSensorController(IFoodSensorService foodSensorService, IFoodMachineService foodMachineService)
        {
            _foodSensorService = foodSensorService;
            _foodMachineService = foodMachineService;

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
        public IActionResult FoodSensorPost(FoodSensorDto foodSensorDto)
        {
            try
            {
                if (Config.Application["previousData"] != foodSensorDto.Distance)
                {
                    Config.Application["previousData"] = foodSensorDto.Distance;
                    _foodSensorService.Add(foodSensorDto);

                }
                return Ok();

            }
            catch (Exception)
            {

                throw;
            }

        }

        //[HttpGet("GetEndData")]
        //public async Task<IActionResult> FoodSensorGet()
        //{
        //    var values = await _foodSensorService.GetEndData();
        //    return Ok(values);
        //}

        [HttpGet("GetMachineEndData")]
        public async Task<IActionResult> FoodMachineGet()
        {
            var values = await _foodMachineService.GetEndData();
            FoodMachineDto foodMachineDto = new FoodMachineDto();
            foodMachineDto.FillingType = values.FillingType;

            return Ok(foodMachineDto);
        }

    }
}
