using Business.Abstract;
using Entities.Dtos;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Business.Concrete
{
    public class ChartManager : IChartService
    {
        private readonly IRainSensorService _rainSensorService;

        public ChartManager(IRainSensorService rainSensorService)
        {
            _rainSensorService = rainSensorService;
        }

        public async Task<List<RainChartDto>> GetChartData()
        {
            var rainSensors = await _rainSensorService.GetList();
            int truevalue = rainSensors.Where(x=>x.isRain == 1).Count();
            int falsevalue = rainSensors.Where(x => x.isRain != 1).Count();
            List<RainChartDto> rainChartDtos = new List<RainChartDto>
            {
                new RainChartDto() { ChartBarName= "Yağmurlu Gün " , ChartValue = truevalue},
                 new RainChartDto() { ChartBarName= "Güneşli Gün " , ChartValue = falsevalue}
            };

            return rainChartDtos;

        }
    }
}
