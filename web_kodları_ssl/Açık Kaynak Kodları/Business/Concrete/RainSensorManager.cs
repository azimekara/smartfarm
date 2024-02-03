using Business.Abstract;
using Business.Hubs;
using DataAccess.Abstract;
using Entities.Concrete;
using Entities.Dtos;
using Microsoft.AspNetCore.SignalR;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Business.Concrete
{
    public class RainSensorManager : IRainSensorService
    {
        private readonly IRainSensorDal _rainSensorDal;
        // private readonly IHubContext<RainHub> _hubContext;

        public RainSensorManager(IRainSensorDal rainSensorDal)
        {
            _rainSensorDal = rainSensorDal;
            //  _hubContext = hubContext;
        }

        public void Add(RainSensoDto rainSensorDto)
        {
            RainSensor rainSensor = new RainSensor();
            {
                rainSensor.isRain = rainSensorDto.isRain;
                rainSensor.Date = DateTime.Now;
            }
            _rainSensorDal.Insert(rainSensor);
            //  _hubContext.Clients.All.SendAsync("ReceivedEndData", GetEndData());
        }

        public async Task<RainSensor> GetEndData()
        {
            var data = await _rainSensorDal.GetList();
            return data.OrderByDescending(x => x.Id).FirstOrDefault();

        }

        public async Task<List<RainSensor>> GetList()
        {
            return await _rainSensorDal.GetList();
        }
    }
}
