using Business.Abstract;
using Entities.Dtos;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace WebApi.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class MoveSensorController : ControllerBase
    {
        private readonly IMoveSensorService _moveSensorService;
        private readonly IDoorActivityService _doorActivityService;
        private readonly IMoveBuzzerService _moveBuzzerService;

        public MoveSensorController(IMoveSensorService moveSensorService, IDoorActivityService doorActivityService, IMoveBuzzerService moveBuzzerService)
        {
            _moveSensorService = moveSensorService;
            _doorActivityService = doorActivityService;
            _moveBuzzerService= moveBuzzerService;

        }

        [HttpPost("SendData")]
        public IActionResult MoveSensorPost(MoveSensorDto moveSensorDto)
        {

            _moveSensorService.Add(moveSensorDto);
            return Ok();
        }

        [HttpGet("GetEndData")]
        public async Task<IActionResult> GetDoorEndData()
        {
            try
            {
                var enddatadoor =  await _doorActivityService.GetEndActivity();
                var enddatabuzzer = await _moveBuzzerService.GetEndData();
               DoorAndBuzzerDto doorAndBuzzerDto = new DoorAndBuzzerDto();
                doorAndBuzzerDto.DoorActivity = enddatadoor.Activity;
                doorAndBuzzerDto.BuzzerActivity = enddatabuzzer.BuzzerActivity;

                return Ok(doorAndBuzzerDto);
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
        }

        //[HttpGet("GetBuzzerEndData")]
        //public async Task<IActionResult> GetBuzzerEndData()
        //{
        //    try
        //    {
        //        var enddata = await _moveBuzzerService.GetEndData();
        //        MoveBuzzerDto moveBuzzerDto = new MoveBuzzerDto();
        //        moveBuzzerDto.BuzzerActivity = enddata.BuzzerActivity;

        //        return Ok(moveBuzzerDto);
        //    }
        //    catch (Exception ex)
        //    {
        //        return BadRequest(ex.Message);
        //    }
        //}
    }
}
